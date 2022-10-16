#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;

int t;
ll a, b;

int main(){
#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	cin>>t;
	while(t--){
		cin>>a>>b;
		// cout<<"________\n";
		ll ans = 0, j = 2;
		while(j <= b){
			ll cur = a/(j+1);
			if(cur < j-1){
				break;
			}
			cur = j-1;
			ans += cur;
			j++;
		}
		while(j <= b){
			ll cur = a/(j+1);
			if(cur <= 0)
				break;
			assert(cur < j-1);
			ll l = j, r = b;
			while(l <= r){
				ll m = (l+r)/2;
				if(a/(m+1) != cur)
					r = m-1;
				else
					l = m+1;
			}
			l = min(l, b+1);
			ans += cur*(l-j);
			// pr(j, l, cur);
			j = l;
		}
		// pr(ans);
		// cout<<'\n';
		cout<<ans<<'\n';
		// cout<<flush;
	}
}