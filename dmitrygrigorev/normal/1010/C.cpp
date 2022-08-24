#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) v[i] %= k;
    int N = k;
    for (int i=0; i < n; i++) N = gcd(N, v[i]);
    vector<int> ans;
    for (int i=0; i < k; i += N) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i=0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}