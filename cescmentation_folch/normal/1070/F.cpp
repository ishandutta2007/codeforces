#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;


int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll n, k = 0;
    cin >> n;
    VI uz, zu, extra;
    
    ll res = 0;
    for (int i = 0; i < n; ++i){
        char a, b;
        ll v;
        cin >> a >> b >> v;
        if (a == '0' and b == '0') extra.push_back(v);
        if (a == '0' and b == '1') zu.push_back(v);
        if (a == '1' and b == '0') uz.push_back(v);
        if (a == '1' and b == '1'){
            ++k;
            res += v;
        }
    }
    sort(uz.rbegin(), uz.rend());
    sort(zu.rbegin(), zu.rend());
    
    int m = min(uz.size(), zu.size());
    for (int j = 0; j < m; ++j) res += uz[j] + zu[j];
    for (int j = m; j < uz.size(); ++j){
        extra.push_back(uz[j]);
    }
    for (int j = m; j < zu.size(); ++j){
        extra.push_back(zu[j]);
    }
    
    sort(extra.rbegin(), extra.rend());
    for (int j = 0; j < min(ll(extra.size()), k); ++j) res += extra[j];
    cout << res << endl;
}