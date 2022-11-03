#include <bits/stdc++.h>
                      
using namespace std;
              
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[100007];


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	multiset<ll> se;
	ll func = 0;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		se.insert(a[i] + func);
		ll ans = 0;
		while(se.size() && *se.begin() - func <= t){
			ans += *se.begin() - func;
			se.erase(se.begin());
		}
		ans += (ll)se.size() * t;
		func += t;
		cout << ans << ' ';
	}   
}