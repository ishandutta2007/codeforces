#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 2000005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL a[N],s[N];
int to[N],fa[N],d[N];
int findr(int x)
{
    if(fa[x]==x)
        return x;
    else
    {
        int t=fa[x];
        fa[x]=findr(fa[x]);
        d[x]=d[x]+d[t];
        return fa[x];
    }
}

void Union(int x,int y)
{
    fa[x]=y;
    d[x]=1;
}

int main()
{
    int n,q,i,j,k,ans;
    LL m;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]),a[i+n]=a[i];
    for(i=n*2;i;i--)
        s[i]=s[i+1]+a[i];
    while(q--)
    {
        ans=INF;
        cin>>m;
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++)
            fa[i]=i,fa[i+n]=i+n;
        for(j=n*2,i=n*2;i;i--)
        {
            while(s[i]-s[j+1]>m) j--;
            to[i]=j+1;
            //debug(to[i]);
        }
        //if(q==1) return 0;
        for(i=1;i<=n;i++)
        {
            j=findr(i);
            while(to[j]<i+n)
            {
                k=to[j];
                Union(j,k);
                j=findr(k);
            }
            findr(i);
            ans=min(ans,d[i]);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);