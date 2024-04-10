#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    set<array<int,2>> sand;
    set<int> col[m];
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                sand.insert({i,j});
                col[j].insert(i);
            }
        }
    }
    vector<int> req(m);
    for(int i=0;i<m;i++) cin >> req[i];
    vector<int> v[n*m];
    vector<int> vr[n*m];
    vector<array<int,2>> edges;
    auto id=[&](int r,int c)->int{return (r*m+c);};
    auto add=[&](int a,int b)
    {
        v[a].push_back(b);
        vr[b].push_back(a);
        edges.push_back({a,b});
    };
    auto nxt=[&](int r,int c)->int
    {
        auto it=col[c].lower_bound(r);
        if(it!=col[c].end()) return id(*it,c);
        else return -1;
    };
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.') continue;
            int x=id(i,j);
            if(i>0&&s[i-1][j]=='#') add(x,id(i-1,j));
            if(j>0&&s[i][j-1]=='#') add(x,id(i,j-1));
            if(j<m-1&&s[i][j+1]=='#') add(x,id(i,j+1));
            for(int d=-1;d<=1;d++)
            {
                if(0<=j+d&&j+d<m)
                {
                    int t=nxt(i+1,j+d);
                    if(t!=-1) add(x,t);
                }
            }
        }
    }
    vector<bool> vis(n*m+1,0);
    vector<int> ord;
    function<void(int)> dfs1=[&](int a)
    {
        vis[a]=1;
        for(int to:v[a]) if(vis[to]==0) dfs1(to);
        ord.push_back(a);
    };
    for(int i=0;i<n*m;i++) if(s[i/m][i%m]=='#'&&vis[i]==0) dfs1(i);
    reverse(ord.begin(),ord.end());
    vector<int> color(n*m,-1);
    function<void(int,int)> dfs2=[&](int a,int c)
    {
        color[a]=c;
        for(int to:vr[a]) if(color[to]==-1) dfs2(to,c);
    };
    int c=0;
    for(int a:ord) if(color[a]==-1) dfs2(a,c++);
    vector<bool> in(c,0);
    for(auto [a,b]:edges) if(color[a]!=color[b]) in[color[b]]=1;
    int res=0;
    for(int i=0;i<c;i++) res+=(in[i]==0);
    cout << res << "\n";
    return 0;
}