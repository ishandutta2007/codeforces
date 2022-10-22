#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

vector<int> g[MAXN];
int p[MAXN],c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i] >> c[i];
        if(p[i]!=-1)
            g[p[i]].push_back(i);
    }

    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        int ok=1;
        for(auto v : g[i])
            ok&=c[v];
        if(c[i] && ok)
            res.push_back(i);
    }

    if(res.empty())
    {
        db(-1)
        return 0;
    }
    for(auto v : res)
        cout << v << ' ';
    cout << '\n';

    return 0;
}