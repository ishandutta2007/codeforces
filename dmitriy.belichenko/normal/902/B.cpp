
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long
const int MOD = 2e9 + 7;
const int N = 3e5;
using namespace std;
vector<int> g[N];
int a[N];
int dfs(int v, int c)
{
    int ans;
    if (c == a[v])
    {
        ans = 0;
        for (auto u : g[v])
        {
            ans += dfs(u, c);
        }
        return ans;
    }
    else
    {
        ans = 1;
        for (auto u : g[v])
        {
            ans = ans + dfs(u, a[v]);
        }
        return ans;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u;
        cin >> u;
        g[u - 1].pb(i + 1);
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << dfs(0 , 0) << "\n";
    return 0;
}