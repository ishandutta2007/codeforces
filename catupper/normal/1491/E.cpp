#include <iostream>
#include <vector>
using namespace std;

int dp[220000];
int sz[220000];
int fib[30];
bool used[220000];
vector<int> edge[220000];

int n, u[220000], v[220000];
int p[220000];
void dfs(int x, int last = -1)
{
    sz[x] = 1;
    for (auto e_id : edge[x]) {
        if (used[e_id])
            continue;
        int to = u[e_id] + v[e_id] - x;
        if (to == last)
            continue;
        dfs(to, x);
        sz[x] += sz[to];
    }
}

int dfs2(int x, int search, int last = -1)
{
    for (auto e_id : edge[x]) {
        if (used[e_id])
            continue;
        int to = u[e_id] + v[e_id] - x;
        if (to == last)
            continue;
        if (sz[to] == search)
            return e_id;
        int ans = dfs2(to, search, x);
        if (ans != -1)
            return ans;
    }
    return -1;
}

bool solve(int x, int rank)
{
    if (rank <= 1)
        return true;
    dfs(x);
    int r = dfs2(x, fib[rank - 2]);
    if (r != -1) {
        used[r] = true;
        int a = u[r], b = v[r];
        if (sz[a] < sz[b])
            swap(a, b);
        return solve(a, rank - 1) && solve(b, rank - 2);
    }
    r = dfs2(x, fib[rank - 1]);
    if (r != -1) {
        used[r] = true;
        int a = u[r], b = v[r];
        if (sz[a] < sz[b])
            swap(a, b);
        return solve(a, rank - 2) && solve(b, rank - 1);
    }
    return false;
}

int main()
{
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 30; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u[i] >> v[i];
        edge[u[i]].push_back(i);
        edge[v[i]].push_back(i);
    }
    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    int k = 2;
    for (; k < 30; k++)
        if (fib[k] == n)
            break;
    if (k == 30) {
        cout << "No" << endl;
        return 0;
    }
    cout << (solve(1, k) ? "Yes" : "No") << endl;
}