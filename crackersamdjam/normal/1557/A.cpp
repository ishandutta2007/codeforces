#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using ld = double;
int const MM = 1e5+5;

int t, n;
ll a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	cout<<fixed<<setprecision(9);
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		sort(a, a+n);
		for(int i = 1; i < n; i++){
			a[i] += a[i-1];
		}
		ld ans = -2e9;
		for(int i = 1; i < n; i++){
			ld v = (a[i-1])/(1.0*i) + (a[n-1]-a[i-1])/(1.0*(n-i));
			ans = max(ans, v);
		}
		cout<<ans<<'\n';
	}
}