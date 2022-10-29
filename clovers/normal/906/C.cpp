#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=30;
bitset<30> bit[N],tmp[N],full;
int n,m;
int ch[N],bl[N];
vector<int> ANS;

void print(bitset<30> T)
{
    for(int i=1;i<=n;i++) if(T.test(i)) printf("1"); else printf("0"); cout<<endl;
}

int mid;
bool dfs(int now,int flag,int pre)
{
    if(now+pre-1>n) return 0;
    if(now==0)
    {
        for(int i=1;i<=n;i++) bit[i]=tmp[i];
        for(int i=1;i<=n;i++)
        {
            if(!bl[i]) continue;
            for(int j=1;j<=n;j++) if(bit[i].test(j)) bit[j]|=bit[i];
        }

        int ret=1;
        for(int i=1;i<=n;i++) if(bit[i]!=full) ret=0;
        if(ret) 
        {
            ANS.clear();
            for(int i=1;i<=n;i++) if(bl[i]) ANS.push_back(i);
        }
        return ret;
    }
    for(int i=pre;i<=n;i++)
    {
        if(bl[i]==flag) continue;
        bl[i]=flag; 
        if(dfs(now-1,flag,i+1)) return 1;
        bl[i]=flag^1;
    }
    return 0;
}

bool check(int mid)
{
    for(int i=1;i<=n;i++) bit[i]=tmp[i];
    //print(bit[1]); print(bit[2]); print(full);
    if(mid>n/2) for(int i=1;i<=n;i++) bl[i]=1;
    else for(int i=1;i<=n;i++) bl[i]=0;
    if(mid>n/2) return dfs(n-mid,0,1);
    else return dfs(mid,1,1);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        tmp[x].set(y); tmp[y].set(x);
    }
    full.reset();
    for(int i=1;i<=n;i++) tmp[i].set(i), full.set(i);
    int l=0,r=n,best;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,best=mid;
        else l=mid+1;
    //cout<<mid<<" "<<TT[mid]<<endl;
    }
    cout<<best<<endl;
    for(int i=0;i<best;i++) printf("%d ",ANS[i]); puts("");
    return 0;
}