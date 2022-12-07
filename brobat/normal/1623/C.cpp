#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n;
vector <int> v;
vector <int> pos;

bool check(int x) {
    vector <int> temp = v;
    for(int i = n - 1; i >= 2; i--) {
        if(temp[i] < x) return false;
        int diff = temp[i] - x;
        diff = min(diff, pos[i]);
        temp[i - 1] += diff/3;
        temp[i - 2] += 2*(diff/3);
    }
    if(temp[1] < x || temp[0] < x) return false;
    return true;
}

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    v.resize(n);
    pos.resize(n);
    forn(i, 0, n) {
        cin >> v[i];
        pos[i] = (v[i]/3)*3;
    }
    cout << binary_search(0, 1E9) << endl;
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
        solve(); 
    }

    return 0;
}