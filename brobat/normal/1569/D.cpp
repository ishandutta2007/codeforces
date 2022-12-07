#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, m, k, t1, t2;
map<int, bool> ver;
map<int, bool> hor;
vector <int> h; // Contains hor, but in increasing order.
vector <int> v; // Contains ver
int ans;
vector<pair<int, int>> vo; // Vertical only points
vector<pair<int, int>> ho; // Horizontal only points

void pre() {
    cin >> n >> m >> k;
    ver.clear(); hor.clear();
    vo.clear(); ho.clear();
    h.clear(); v.clear();
    ans = 0;
    forn(i, 0, n) {
        cin >> t1;
        ver[t1] = true;
        v.push_back(t1);
    }
    forn(i, 0, m) {
        cin >> t1;
        hor[t1] = true;
        h.push_back(t1);
    }
    forn(i, 0, k) {
        cin >> t1 >> t2;
        if(ver[t1]&&hor[t2]) continue;
        if(ver[t1]) {
            vo.push_back({t2, t1});
        }
        if(hor[t2]) {
            ho.push_back({t1, t2});
        }
    }
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    sort(ho.begin(), ho.end());
    sort(vo.begin(), vo.end());
}  

void debug() {
    for(auto i : h) cout << i << " ";
    cout << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
    for(auto i : ho) cout << i.first << "," << i.second << " ";
    cout << endl;
    for(auto i : vo) cout << i.first << "," << i.second << " ";
    cout << endl;
}

void vertical() {
    int x = v.size();
    int y = ho.size();
    int i = 0, j = 0;
    while(i<(x-1) && j<y) {
        int a1 = v[i];
        int a2 = v[i+1];
        // Find all hor points between a1 and a2 in X co-ordinate.
        // ho[j].first is between a1 and a2.
        map<int, int> store;
        while(ho[j].first < a2) {
            if(ho[j].first > a1) store[ho[j].second]++;
            j++;
            if(j>=y) break;
        }
        int sum_store = 0;
        for(auto t3 : store) sum_store += t3.second;
        ans += (sum_store*(sum_store-1))/2;
        for(auto t3 : store) {
            ans -= (t3.second*(t3.second-1))/2;
        }
        i++;
    }
}

void horizontal() {
    int x = h.size();
    int y = vo.size();
    int i = 0, j = 0;
    while(i<(x-1) && j<y) {
        int a1 = h[i];
        int a2 = h[i+1];
        // Find all hor points between a1 and a2 in X co-ordinate.
        // ho[j].first is between a1 and a2.
        map<int, int> store;
        while(vo[j].first < a2) {
            if(vo[j].first > a1) store[vo[j].second]++;
            j++;
            if(j>=y) break;
        }
        int sum_store = 0;
        for(auto t3 : store) sum_store += t3.second;
        ans += (sum_store*(sum_store-1))/2;
        for(auto t3 : store) {
            ans -= (t3.second*(t3.second-1))/2;
        }
        i++;
    }
}

void solve() {
    pre();
    // debug();
    vertical();
    horizontal();
    cout << ans << endl;
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