/*  * In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 20000001;
int a[M];
ll dp[M];
vector <int> divs[M];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    set <int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                a[i]++;
                st.insert(i);
                 if (i * i != x) {
                    a[x / i]++;
                    st.insert(x / i);
                 }
            }
        }
    }
    vector <int> v;
    for (auto x2 : st) {
        v.push_back(x2);
        int x = x2;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                divs[i].push_back(x2);
                if (i * i != x) {
                    divs[x / i].push_back(x2);
                }
            }
        }
    }
    reverse(v.begin(), v.end());
    for (auto i : v) {
        dp[i] = (ll)a[i] * (ll)i;
        for (auto j : divs[i]) {
            dp[i] = max(dp[i], dp[j] + (ll)i * (ll)(a[i] - a[j]));
        }
    }
    cout << dp[1];
}