#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int minSwaps(vector <int> &v, int n, int x) {
    int index = 0; // index from which we need to consider. v[0....(index-1)] is sorted. 
    int cnt = 0; // number of swaps
    while(index < n) {
        if(is_sorted(v.begin() + index, v.end())) return cnt;
        vector <int> less;
        vector <int> equal;
        forn(i, index, n) {
            if(v[i] < x) less.push_back(v[i]);
            if(v[i] == x) equal.push_back(i);
        }
        sort(less.begin(), less.end());
        forn(i, 0, less.size()) {
            if(v[index + i] != less[i]) return -1;
        }
        // Now we know that upto [index + less.size() - 1] is sorted. We need to consider from [index + less.size()]
        index += less.size();
        int jump = -1;
        if(equal.size() != 0) {
            if(equal[0] != index) jump = index;
            forn(i, 1, equal.size()) {
                if(equal[i] > equal[i - 1] + 1) {
                    if(equal[i] > equal[i - 1] + 2) return -1;
                    if(jump != -1) return -1;
                    jump = equal[i - 1] + 1;
                }
            }
        }
        index += equal.size();
        if(jump != -1) {
            x = v[jump];
        }
        else {
            if(index < n) {
                x = v[index];
                index++;
            }
        }
        cnt++;
    }
    return cnt;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    cout << minSwaps(v, n, x) << endl;
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