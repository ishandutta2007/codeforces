#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

const long long MOD = 1e9+123;

int m, n;
vector <ll>a;
vector <ll>h;
ll H;

ll pot(ll b, ll e) {
    if (e == 0) return 1;
    if (e%2) return (b*pot(b, e-1))%MOD;
    return pot((b*b)%MOD, e/2);
    
}

ll hasho(ll x) {
    int p = upper_bound(a.begin(), a.end(), x-1)-a.begin()-1;
    ll ha = 0;
    if (p >= 0) ha += (h[p]*pot(2, m-x))%MOD;
    if (p >= 0) {
        ha = (ha+(h[n-1]-h[p]+MOD)*(pot(2, x*(MOD-2))))%MOD;
    }
    else {
        ha = (ha+h[n-1]*(pot(2, x*(MOD-2))))%MOD;
    }
    return ha;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a = vector <ll>(n);
    H = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        H = (H+pot(2, (m-a[i])%m))%MOD;
    }
    sort(a.begin(), a.end());
    h = vector <ll>(n, 0);
    h[0] = pot(2, a[0]);
    for (int i = 1; i < n; ++i) {
        h[i] = (h[i-1]+pot(2, a[i]))%MOD;
    }
    vector <ll>ans;
    for (int i = 0 ; i < n; ++i) {
        ll x = (a[0]+a[i])%m;
        if (hasho(x) == H) ans.push_back(x);
        
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";        
    }
    cout << endl;
}