#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 150150;
const int INF = 0x3f3f3f3f;
int f[N];
int g[N];
int n;
char s[N];

inline bool one(int a, int b, int c) {
    return s[a] == 'o' && s[b] == 'n' && s[c] == 'e';
}

inline bool twone(int x) {
    return s[x] == 't' && s[x+1] == 'w' && s[x+2] == 'o' && s[x+3] == 'n' && s[x+4] == 'e';
}

inline bool two(int a, int b, int c) {
    return s[a] == 't' && s[b] == 'w' && s[c] == 'o';
}

inline bool good(int a, int b, int c) {
    return !one(a, b, c) && !two(a, b, c);
}

void solve() {
    cin >> (s+1);
    n = strlen(s+1);
    
    vector<int> ans;
    int k=0;

    for (int i=1; i<=n-4; ++i) {
        if (twone(i)) {
            s[i+2] = 'x';
            ans.push_back(i+2);
        }
    }
    for (int i=1; i<=n-2; ++i) {
        if (one(i, i+1, i+2)) {
            s[i+1] = 'x';
            ans.push_back(i+1);
        }
    }
    for (int i=1; i<=n-2; ++i) {
        if (two(i, i+1, i+2)) {
            s[i+1] = 'x';
            ans.push_back(i+1);
        }
    }
    //cerr << ":: " << (s+1) << endl;
    cout << ans.size() << "\n";
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}