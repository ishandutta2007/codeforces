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
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int p[100005],t[2][100005],cou[100005],flag[100005],vis[100005],sum,a,b;
map<int,int> mp;
void dfs(int x,int q)
{
    int v;
    if(q==0) v=mp[a-p[x]];
    else v=mp[b-p[x]];
    //printf("q=%d x=%d v=%d\n",q,x,v);
    vis[x]=1;
    sum++;
    if(sum%2==1) flag[x]=flag[v]=q;
    if(sum>1&&cou[x]==1) return;
    q^=1;
    dfs(v,q);
}
int main()
{
    int n,i,f1=1;
    cin>>n>>a>>b;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        mp[p[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        if(mp[a-p[i]])
            t[0][i]=mp[a-p[i]],cou[i]++;
        if(mp[b-p[i]])
            t[1][i]=mp[b-p[i]],cou[i]++;
        if(cou[i]==0)
            f1=0;
    }
    if(!f1)
    {
        printf("NO\n");
        return 0;
    }
    else
    {
        for(i=1;i<=n;i++)
            if(!vis[i]&&cou[i]==1)
            {
                sum=0;
                //printf("i=%d\n",i);
                //printf("***** %d\n",mp.count(a-p[i]));
                dfs(i,mp[b-p[i]]>0?1:0);
                if(sum%2==1) f1=0;
            }
    }
    if(!f1)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(i=1;i<=n;i++)
            printf("%d ",flag[i]);
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);