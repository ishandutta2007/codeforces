#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;

int D[MAXN], Parent[MAXN];
vector<int> G[MAXN];
int last, n;

void dfs(int node, int p) {
    D[node] = D[p] + 1;
    if(D[last] < D[node]) last = node;

    for(auto vec : G[node])
        if(vec != p)
            dfs(vec, node);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug", "r", stdin);
    #endif // ONLINE_JUDGE

    int d, h;
    cin >> n >> d >> h;
    if(2 * h < d) {cout << -1; return 0; }

    if(n == 2) {cout << "1 2\n"; return 0;}
    if(d == 1) {cout << -1; return 0;}


    if(d == h) {
        for(int i = 2; i <= d + 1; ++i) {
            cout << i << " " << i-1 << '\n';
        }
        for(int i = d + 2; i <= n; ++i) {
            cout << i << " " << d << '\n';
        }
        return 0;
    }


    for(int i = 2; i <= h + 1; ++i) {
        cout << i << " " << i-1 << '\n';
    }

    if(h + 2 > n) return 0;

    cout << h + 2 << ' ' << 1 << '\n';

    for(int i = h + 3; i <= d + 1; ++i) {
        cout << i << " " << i-1 << '\n';
    }

    for(int i = d + 2; i <= n; ++i)
        cout << i << " " << 1 << '\n';

    return 0;

    return 0;
}