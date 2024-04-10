//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
#define MOD 1000000007
using namespace std;
int T,n,m,p[100005],a,b,size[100005],fa[100005],v[100005],g[100005],ans;
vector<int> son[100005];
void dfs(int now)
{
    size[now]=1;
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(son[now][i]==fa[now])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i]]=now;
        dfs(son[now][i]);
        size[now]+=size[son[now][i]];
    }
}
bool cmp(const int &A,const int &B)
{
    return A>B;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            son[i].clear();
        }
        for(int i=1;i<n;++i)
        {
            cin>>a>>b;
            son[a].push_back(b);
            son[b].push_back(a);
        }
        dfs(1);
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            cin>>p[i];
        }
        if(m<n)
        {
            sort(p+1,p+1+m,cmp);
            for(int i=1;i<=m;++i)
            {
                v[i]=p[i];
            }
            for(int i=m+1;i<n;++i)
            {
                v[i]=1;
            }
        }
        else
        {
            sort(p+1,p+1+m);
            v[1]=1;
            for(int i=n-1;i<=m;++i)
            {
                (v[1]*=p[i])%=MOD;
            }
            for(int i=2;i<=n;++i)
            {
                v[i]=p[n-i];
            }
        }
        for(int i=2;i<=n;++i)
        {
            g[i-1]=size[i]*(size[1]-size[i]);
        }
        sort(g+1,g+n,cmp);
        for(int i=n-1;i;--i)
        {
            (ans+=g[i]%MOD*v[i])%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}