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
int const MM = 2e5+5;

int t, n;
ll a[MM], pre[MM], suf[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			pre[i] = suf[i] = 0;
			if(i == 1) continue;
			ans += abs(a[i]-a[i-1]);
			if(a[i] > a[i-1]){
				pre[i] = a[i-1]-a[i];
			}
			else{
				suf[i-1] = a[i]-a[i-1];
			}
		}
		for(int i = 1; i <= n; i++){
			pre[i] += pre[i-1];
		}
		ll mn = LLONG_MAX/2;
		suf[n+1] = 0;
		for(int i = n; i; i--){
			suf[i] += suf[i+1];
			mn = min(mn, a[i]+pre[i]+suf[i]);
			// cerr<<a[i]+pre[i]+suf[i]<<' ';
		}
		// cerr<<endl;
		ans += abs(mn);
		// pr("mn", mn);
		// pr("ans", ans, "\n");
		cout<<ans<<'\n';
	}	
}