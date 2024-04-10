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
using namespace std;
int T,n,a,b,fa[100005],siz[100005],v[100005];
vector<int> son[100005];
void init(int now)
{
    siz[now]=1;
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(fa[now]==son[now][i])
        {
            swap(son[now][i],son[now].back());
            --i;
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]]=now;
        init(son[now][i]);
        siz[now]+=siz[son[now][i]];
    }
}
void dfs(int now)
{
    v[now]=siz[1]-siz[now];
    for(int i=0;i<(int)son[now].size();++i)
    {
        v[now]=max(v[now],siz[son[now][i]]);
        dfs(son[now][i]);
    }
}
int fin(int now)
{
    if(son[now].size())
    {
        return fin(son[now][0]);
    }
    else
    {
        return now;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            son[i].clear();
            fa[i]=0;
        }
        for(int i=1;i<n;++i)
        {
            cin>>a>>b;
            son[a].push_back(b);
            son[b].push_back(a);
        }
        init(1);
        dfs(1);
        int MIN=INF;
        for(int i=1;i<=n;++i)
        {
            MIN=min(MIN,v[i]);
        }
        vector<int> z;
        for(int i=1;i<=n;++i)
        {
            if(v[i]==MIN)
            {
                z.push_back(i);
            }
        }
        if(z.size()==1)
        {
            cout<<1<<' '<<son[1][0]<<endl;
            cout<<1<<' '<<son[1][0]<<endl;
        }
        else
        {
            if(fa[z[0]]!=z[1])
            {
                swap(z[0],z[1]);
            }
            int k=fin(z[0]);
            cout<<k<<' '<<fa[k]<<endl;
            cout<<k<<' '<<z[1]<<endl;
        }
    }
    return 0;
}