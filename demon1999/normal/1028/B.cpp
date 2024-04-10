#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

int n, m;
int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int k = n / 9 + 1;
    forn (i, k) cout << 9;
    cout << "\n";
    forn (i, k) cout << 9;
    forn (i, k - 1) cout << 0;
    cout << 1;
    cout << "\n";
    return 0;
}