#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n+1,0);
    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        if(c[i]==1) (x==0?x:y)=i;
    }
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> path={y};
    function<bool(int,int)> dfs=[&](int a,int p)->bool
    {
        if(a==y) return 1;
        for(int to:v[a])
        {
            if(to!=p&&dfs(to,a))
            {
                path.push_back(a);
                return 1;
            }
        }
        return 0;
    };
    dfs(x,0);
    int len=path.size();
    int root=path[min(len-1,2)];
    bool all=0;
    vector<int> s(n+1,0);
    vector<int> ch(n+1,0);
    function<void(int,int)> go=[&](int a,int p)
    {
        s[a]=c[a];
        for(int to:v[a])
        {
            if(to==p) continue;
            go(to,a);
            s[a]+=s[to];
            ch[a]|=(c[to]==1);
        }
        for(int to:v[a]) all|=(to!=p&&c[to]==1&&s[to]<s[a]);
        all|=(c[a]==1&&s[a]>1);
    };
    go(root,0);
    vector<bool> res(n+1,0);
    function<void(int,int,bool)> color=[&](int a,int p,bool ok)
    {
        ok|=(ch[a]);
        res[a]=ok;
        for(int to:v[a]) if(to!=p) color(to,a,ok);
    };
    color(root,0,all);
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}