#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> e(n*n);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        for(int j=1;j<=n;j++) e[n*i+j-1]={a*j,i};
    }
    ranges::sort(e);
    vector<int> c;
    vector<vector<int>> v;
    int idx=-1;
    for(int i=0;i<n*n;i++)
    {
        if(i==0||e[i][0]!=e[i-1][0])
        {
            idx++;
            v.push_back({});
            c.push_back(e[i][0]);
        }
        v[idx].push_back(e[i][1]);
    }
    vector<int> vis(idx+1,-1);
    vector<int> yx(n,-1);
    auto go=[&](auto &&self,int a,int t)->bool
    {
        vis[a]=t;
        for(int to:v[a])
        {
            if(yx[to]==-1||(vis[yx[to]]<t&&self(self,yx[to],t)))
            {
                yx[to]=a;
                return 1;
            }
        }
        return 0;
    };
    int cnt=0;
    ll res=0;
    for(int i=0;i<=idx;i++)
    {
        if(cnt<n&&go(go,i,cnt))
        {
            res+=c[i];
            cnt++;
        }
    }
    cout << res << "\n";
    return 0;
}