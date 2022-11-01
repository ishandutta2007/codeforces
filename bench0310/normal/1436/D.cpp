#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> val(N,0);
vector<ll> c(N,0);
vector<int> leaves(N,0);
ll res=0;

void dfs(int a)
{
    c[a]=val[a];
    leaves[a]=(v[a].empty());
    for(int to:v[a])
    {
        dfs(to);
        c[a]+=c[to];
        leaves[a]+=leaves[to];
    }
    res=max(res,(c[a]+leaves[a]-1)/leaves[a]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    for(int i=1;i<=n;i++) cin >> val[i];
    dfs(1);
    cout << res << "\n";
    return 0;
}