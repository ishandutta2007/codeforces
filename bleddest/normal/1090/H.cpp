#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define puts sykk
#define endl '\n'

#define mp make_pair
#define pb push_back

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream &out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream &out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int m;
string s;
int dp[200043][20];

bool read() {
    cin >> m >> s;
    return true;
}

void solve() {
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(i < (1 << (j + 1)))
                dp[i][j] = 0;
            else
            {
                int i1 = i - (1 << j);
                int i2 = i1 - 1;
                dp[i][j] = dp[i - (1 << (j + 1))][j] + (s[i1] == s[i2] ? 0 : 1);
            }
        }
    }
    int q;
    cin >> q;
    forn(i, q)
    {
        int l, r;
        cin >> l >> r;
        ++r;
        int ans = 0;
        int len = r - l;
        for(int k = 0; (1 << k) < len; k++)
        {
            int psum = dp[r][k] - dp[l][k];
            ans += min(psum, (len >> (k + 1)) - psum);
        }
        cout << (ans + 1) / 2 << endl;
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
#endif
    }
    return 0;
}