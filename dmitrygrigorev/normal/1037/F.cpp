#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
int calc(int n, int k){
    if (n<=0) return 0;
    k--;
    int kvo = (n-1) / k + 1;
    int A = (kvo*n)%MOD, B = ((kvo * (kvo-1)) / 2) % MOD;
    B *= k;
    //cout << n << " " << k << " " << A << " " << B << endl;
    return (A-B)%MOD;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int pref[n], suff[n];
    vector<pair<int, int> > st;
    for (int i=0; i < n; i++){
        while (st.size() && st.back().first < v[i]) st.pop_back();
        if (st.size()) pref[i] = st.back().second;
        else pref[i] = -1;
        st.push_back(make_pair(v[i], i));
    }
    st.clear();
    for (int i=n-1; i >= 0; i--){
        while (st.size() && st.back().first <= v[i]) st.pop_back();
        if (st.size()) suff[i] = st.back().second;
        else suff[i] = n;
        st.push_back(make_pair(v[i], i));
    }
    int ans = 0;
    for (int i=0; i < n; i++){
        int len = suff[i] - pref[i] - 1;
        int A = i-pref[i]-1, B = suff[i] - i-1;
        ans += (calc(len, k) - calc(A, k) - calc(B, k)) * v[i];
        //cout << ans << "!!" << len << " " << A << " " << B << endl;
    }
    for (int i=0;i<n;i++) ans -= v[i];
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans;

}