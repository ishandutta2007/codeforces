#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> st;
int n;

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        st[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}
// Character x is currently present at position get(x).
int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return st[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return st[v] + get(v*2, tl, tm, pos);
    else
        return st[v] + get(v*2+1, tm+1, tr, pos);
}

int solve() {
    string s, t; cin >> n >> s >> t;
    if(s < t) return 0;
    string tt = s; sort(tt.begin(), tt.end()); if(tt >= t) return -1;
    deque <int> occ[26];
    forn(i, 0, n) occ[s[i] - 'a'].push_back(i);
    st.clear(); st.resize(4*n, 0);
    forn(i, 0, n) update(1, 0, n - 1, i, i, i);
    int ans = INF;
    int curr = 0;
    set <int> done;
    forn(i, 0, n) done.insert(i);
    for(int i = 0; i < n; i++) {
        int val = *done.begin();
        int p = s[val] - 'a';
        int q = t[i] - 'a';
        if(p < q) {
            ans = min(ans, curr);
            break;
        }
        int mn = INF;
        forn(j, 0, q) {
            if(occ[j].size() == 0) continue;
            mn = min(mn, get(1, 0, n - 1, occ[j][0]) - i);
        }
        ans = min(ans, curr + mn);
        if(occ[q].size() == 0) break;
        int ind = get(1, 0, n - 1, occ[q][0]);
        update(1, 0, n - 1, 0, occ[q][0] - 1 , 1);
        done.erase(occ[q][0]);
        occ[q].pop_front();
        curr += ind - i;
    }
    return ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        cout << solve() << endl; 
    }

    return 0;
}