#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

vector <int> p;

void print_ans(vector <int> &v, int n) {
    int sz = 0;
    for(auto i : v) sz += i;
    vector <int> c;
    int t = 0;
    for(auto i : v) {
        forn(j, 0, i) c.push_back(p[t]);
        t++;
    }
    // for(auto i : c) cout << i << " ";
    t = 0;
    forn(i, 0, sz - n + 1) t += c[i];
    cout << t << " ";
    forn(i, sz - n + 1, sz) cout << c[i] << " ";
    cout << endl;
}

void pre() {
    p.push_back(1);
    forn(i, 1, 10) p.push_back(p[i-1]*10);
}

void solve() {
    int n; string s;
    cin >> s >> n;
    int m = s.length();
    vector <int> v(m, 0);
    forn(i, 0, m) v[i] = s[m - 1 - i] - '0';
    int sz = 0;
    for(auto i : v) sz += i;
    while(sz < n) {
        forn(i, 1, m) {
            if(v[i] > 0) {
                v[i]--;
                v[i-1] += 10;
                sz += 9;
                break;
            }
        }
    }
    print_ans(v, n);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    pre();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}