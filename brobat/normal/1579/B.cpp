#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void shift(int l, int r, int d, vector<int>& v) {
    // Shift v[l...r] by d.
    int n = v.size();
    vector <int> c(n);
    forn(i, 0, n) {
        if(i < l || i > r) c[i] = v[i]; 
    }
    int sz = r - l + 1;
    forn(i, 0, r-l+1) {
        int curr = v[l+i];
        c[l + (i - d + sz)%sz] = curr;
    }
    v = c;
}

int find(int x, vector<int>& v, int start) {
    int n = v.size();
    forn(i, start, n) {
        if(v[i]==x) return i;
    }
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    vector <int> st(n); // sorted.
    forn(i, 0, n) {
        cin >> v[i];
        st[i] = v[i];
    }
    sort(st.begin(), st.end());
    vector<vector<int>> ans;
    forn(i, 0, n) {
        if(v[i]==st[i]) continue;
        int ind = find(st[i], v, i);
        shift(i, ind, ind - i, v);
        ans.push_back({i+1, ind+1, ind - i});
        // for(auto i : v) cerr << i << " ";
        // cerr << endl;
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}