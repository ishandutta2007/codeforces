#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

ll mod =  1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int m = t.size();
    vi A(m + n);
    vpi SS(k);
    for (int i = 0; i < k; ++i) SS[i] = pi(0, i);
    for (int i = 0; i < m; ++i) {
        int l = t[i] - 'a';
        SS[l] = pi(i + 1, l);
        A[i] = l;
    }
//     cerr << 1 << endl;
    sort(SS.begin(), SS.end());
    for (int i = 0; i < n; ++i) {
        A[m + i] = SS[i%k].second;
    }
//     cerr << 2 << endl;
    ll Dp[n + m + 1];
    ll sum[n + m + 1];
    ll last[k];
    memset(last, -1, sizeof last);
    Dp[0] = 1;
    sum[0] = 1;
    for (int i = 0; i < m + n; ++i) {
        Dp[i + 1] = sum[i];
        if (last[A[i]] != -1) Dp[i + 1] = (Dp[i + 1] + mod - sum[last[A[i]]])%mod;
        sum[i + 1] = (sum[i] + Dp[i + 1])%mod;
        last[A[i]] = i;
    }
    
    cout << sum[n + m] << endl;
}