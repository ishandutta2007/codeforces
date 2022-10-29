#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int N=300005;
const int inf=(int)1e9;
int TTT=1,n,a[N];
vector<pii> Q[N];

namespace BIT{
    int sum[N];
    int lowbit(int x){return x&(-x);}
    void update(int pos)
    {
        for(int i=pos;i<=n;i+=lowbit(i)) sum[i]++;
    }
    int query(int pos)
    {
        int ret=0;
        for(int i=pos;i>0;i-=lowbit(i)) ret+=sum[i];
        return ret;
    }
}

int m,ans[N],tot=0,bl[N],D[N];
vector<int> v[N];
void init()
{
    memset(bl,0,sizeof(bl));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]>i) a[i]=inf;
        else a[i]=i-a[i];
    }
    for(int i=1;i<=n;i++) v[i].clear() , Q[i].clear();
    for(int i=1;i<=m;i++) 
    {
        int L,R; scanf("%d%d",&L,&R);
        L++; R=n-R;
        Q[L].push_back(mk(R,i));
    }
    for(int i=1;i<=n;i++)
    {
        if(tot<a[i]) continue;
        int l=1,r=i,mid=i;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(tot-BIT::query(mid-1)>=a[i]) l=mid+1,D[i]=mid;
            else r=mid-1;
        }
        if(D[i])
        {
            tot++;
            BIT::update(D[i]);
            v[D[i]].push_back(i);
        }
    }
}

void solve()
{
    for(int i=1;i<=n;i++) BIT::sum[i]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<(int)v[i].size();j++) BIT::update(v[i][j]);
        for(int j=0;j<(int)Q[i].size();j++)
        {
            pii now=Q[i][j];
            ans[now.second]=BIT::query(now.first)-BIT::query(i-1);
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}

int main()
{
    while(TTT--){init(); solve();}
    return 0;
}