#include <iostream>
#include <vector>

using namespace std;

const int N = (int)1e4 + 5;

vector <int> g[N];
int nc2[N];
bool seen[N] = {0};

void pre()
{
    nc2[0] = 1;

    for (int i = 1; i <= N; ++i)
        nc2[i] = (i*(i-1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    pre();

    int n, u, v;
    cin >> n;

    for (int i = 0; i < n-1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        ans += nc2[g[i].size()];
    }

    cout << ans;
    return 0;
}