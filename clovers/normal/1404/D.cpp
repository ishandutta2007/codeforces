#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef pair<int,int> pii;
#define mk make_pair
int n,pos[N],vis[N],bl[N];
pii a[N];
vector<int> ans;

int f(int x)
{
    int to; if(x<=n) to=x+n; else to=x-n;
    return to;
}

long long sum=0;
vector<int> tmp,TMP;
void insert(int x,int len)
{
    //cout<<x<<endl;
    if(vis[(x>n ? x-n : x)]) 
    {
        if(len%2==1) 
        {
            tmp.clear();
            tmp=TMP;
        }
        return;
    }
    sum+=x;
    ans.push_back(x); vis[(x>n ? x-n : x)]=1; TMP.push_back(x);
    int oth=(x==a[pos[x]].first ? a[pos[x]].second : a[pos[x]].first);
    int to=f(oth);
    insert(to,len+1);
}

int main()
{
    scanf("%d",&n);
    if(n%2==0)
    {
        puts("First");
        for(int i=1;i<=2*n;i++)
        {
            printf("%d ",(i>n ? i-n : i));
        }
        fflush(stdout);
        return 0;
    }
    puts("Second");
    fflush(stdout);
    for(int i=1;i<=n;i++) a[i].first=a[i].second=0;
    for(int i=1;i<=2*n;i++)
    {
        int x; scanf("%d",&x); pos[i]=x;
        if(a[x].first) a[x].second=i;
        else a[x].first=i;        
    }
    ans.clear(); memset(vis,0,sizeof(vis));
    TMP.clear(); insert(2*n,0);
    for(int i=1;i<n;i++) if(!vis[i]) TMP.clear(), insert(i,0);
    if(sum%(2*n)!=0)
    {
        for(int i=0;i<(int)tmp.size();i++) bl[tmp[i]]=1;
    }
    for(int i=0;i<n;i++) 
    {
        if(bl[ans[i]]==1) printf("%d ",f(ans[i]));
        else printf("%d ",ans[i]);
    }
}