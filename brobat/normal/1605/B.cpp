#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

vector <int> v;
vector<vector<int>> ans;
int n; char c;

// void solve(int first, int last) {
//     if(first >= last) return;
//     if(v[first] == 0) solve(first + 1, last);
//     else if(v[last] == 1) solve(first, last - 1);
//     else {

//     }
// }

void solve() {
    cin >> n;
    v.resize(n);
    ans.clear();
    forn(i, 0, n) {
        cin >> c;
        if(c=='0') v[i] = 0;
        else v[i] = 1;
    }
    if(is_sorted(v.begin(), v.end())) cout << 0 << endl;
    else {
        vector <int> ans;
        cout << 1 << endl;
        int cnt = count(v.begin(), v.end(), 0);
        forn(i, 0, n) {
            if(i < cnt) {
                if(v[i] == 1) ans.push_back(i); 
            }
            else {
                if(v[i] == 0) ans.push_back(i);
            }
        }
        cout << ans.size() << " ";
        for(auto i : ans) cout << i + 1 << " ";
        cout << endl;
    }
    // solve(0, n - 1);
}

// void solve(int last) {
//     if(last <= 0) return;
//     if(is_sorted(v.begin(), v.end())) return;
//     int cnt = count(v.begin(), v.end(), 1);
//     if(v[last] == 1) {
//         solve(last - 1);
//         return;
//     }
//     int cnt_z = 0;
//     int it = last;
//     vector <int> z;
//     vector <int> o;
//     while(v[it] == 0 && cnt_z <= cnt) {
//         cnt_z++;
//         z.push_back(it);
//     }
//     int s2 = it;
//     // Now swap cnt_z 1s with cnt_z 0s.
//     while(it >= 0 && o.size() <= cnt_z) {
//         if(v[it] == 1) {
//             o.push_back(it);
//         }
//         it--;
//     }
//     sort(o.begin(), o.end());
//     sort(z.begin(), z.end());
//     for(auto i : z) o.push_back(i);
//     ans.push_back(o);
//     solve(s2);
// }

// void solve() {
//     int n;
//     cin >> n;
//     v.resize(n);
//     forn(i, 0, ans.size()) ans[i].clear();
//     ans.clear();
//     char c;
//     forn(i, 0, n) {
//         cin >> c;
//         if(c=='0') v[i] = 0;
//         else v[i] = 1;
//     }
//     solve(n - 1);
//     cout << ans.size() << endl;

// }

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