#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

vector <int> squares, cubes, sixes;

void pre() {
    forn(i, 0, 1E5) squares.push_back(i*i);
    forn(i, 0, 2E3) cubes.push_back(i*i*i);
    forn(i, 0, 1E2) sixes.push_back(i*i*i*i*i*i);
}

int index(vector <int> &v, int x) {
    return (int)(upper_bound(v.begin(), v.end(), x) - v.begin() - 1);
}

void solve() {
    int n;
    cin >> n;
    cout << index(squares, n) + index(cubes, n) - index(sixes, n) << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    pre();
    while(T--) solve();

    return 0;
}