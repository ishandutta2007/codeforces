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
int const MM = 1005;

int n;
ll a[MM];
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i += 2){
		ll sum = 0, must = 0;
		for(int j = i+1; j <= n; j++){
			if(j%2 == 0){
				//try adding
				ll hi = min(a[i]+sum+must, a[j]);
				ll lo = max({must, sum+must, 0LL});
				if(i+1 == j)
					lo = max(lo, 1LL);

				// pr(i, j, hi, lo, ",", must, sum+must);

				if(hi >= lo){
					ans += hi-lo+1;
					// pr("add", i, j, hi-lo+1);
				}

				ll sub = min(must, a[j]);
				must -= sub;
				ll rem = a[j]-sub;
				sum -= rem;
			}
			else{
				must += a[j];
			}
			if(a[i]+sum+must < 0){
				//negative
				break;
			}
		}
	}
	cout<<ans<<'\n';
}