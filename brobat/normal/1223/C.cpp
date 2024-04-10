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
vector <int> p;
int x, a, y, b;
int l;
int k;

bool check(int v) {
    int common = v / l;
    int first = v / a;
    int second = v / b;
    first -= common;
    second -= common;
    int sum = 0;
    if(x > y) {
        // Choose first values before second.
        for(int i = 0; i < common; i++) sum += (x + y) * p[i]/100;
        for(int i = 0; i < first; i++) sum += (x) * p[i + common]/100;
        for(int i = 0; i < second; i++) sum += (y) * p[i + common + first]/100;
        return (sum >= k);
    }
    for(int i = 0; i < common; i++) sum += (x + y) * p[i]/100;
        for(int i = 0; i < second; i++) sum += (y) * p[i + common]/100;
        for(int i = 0; i < first; i++) sum += (x) * p[i + common + second]/100;
        return (sum >= k);
}

// bool check(int x) {
//     // Check if x tickets are enough.
//     vector <int> t;
//     for(int i = 1; i <= x; i++) {
//         if(i % a == 0 || i % b == 0) {
//             t.push_back(i);
//         }
//     }
//     // sort(t.begin(), t.end(), [&](int i, int j) {
//     //     bool fs = i % a == 0 && i % b == 0;
//     //     bool sn = j % a == 0 && j % b == 0;
//     //     if(fs && sn) return (i < j);
//     //     if(fs) return true;
//     //     if(sn) return false;
//     //     if(x > y) {
//     //         if(i % a == 0 && j % a == 0) return (i < j);
//     //         if(i % a == 0) return true;
//     //         return false;
//     //     }
//     //     if(x < y) {
//     //         if(i % b == 0 && j % b == 0) return (i < j);
//     //         if(i % b == 0) return true;
//     //         return false;
//     //     }
//     //     return (i < j);
//     // });
//     int sum = 0;
//     forn(i, 0, x) {
//         if(t[i] % a == 0 && t[i] % b == 0) {
//             sum += (x + y) * p[i] / 100;
//         }
//         else if(t[i] % a == 0) {
//             sum += x * p[i]/100;
//         }
//         else {
//             sum += y * p[i]/100;
//         }
//     }
//     return (sum >= k);
// }

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(!check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    if(ans == n) return -1;
    return ans + 1;
}

void solve() {
    cin >> n;
    p.resize(n);
    forn(i, 0, n) cin >> p[i];
    sort(p.begin(), p.end(), greater<int>());
    cin >> x >> a >> y >> b >> k;
    l = a * b / __gcd(a, b);
    cout << binary_search(0, n) << endl;
    // cout << "F";
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