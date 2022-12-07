#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef cc_hash_table<int, int, hash<int>> ht;

const int MAXN = 1000005;

vector <int> d(MAXN, 0);
// ht s;
// unordered_map<int, int> s;
vector <int> s(19 * 1000000, 0);

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    

    int n, m;
    cin >> n >> m;
    vector <int> f;
    for(int i = 2; i <= n; i++) {
        if(d[i] == 0) {
            d[i] = 1;
            long long curr = i;
            int cnt = 0;
            while(curr <= n) {
                cnt++;
                d[curr] = 1;
                curr *= i;
            }
            f.push_back(cnt);
        }
    }
    long long c = 0;
    map <int, int> ans;
    for(int i = 1; i <= 19; i++) {
        // cout << i << " ";
        for(int j = 1; j <= m; j++) {
            // if(i * j <= m) continue;
            if(s[i * j] == 0) {
                s[i * j] = 1;
                c++;
            }
        }
        ans[i] = c;
    }
    long long z = 0;
    for(auto i : f) {
        z += ans[i];
    }
    cout << z + 1;
    
    return 0;
}