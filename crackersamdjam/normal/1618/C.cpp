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

int t, n;
ll a[105];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		ll g[2] = {0, 0};
		for(int i = 0; i < n; i++){
			cin>>a[i];
			g[i%2] = __gcd(g[i%2], a[i]);
		}
		bool ok = 1;
		for(int i = 0; i < n; i += 2){
			if(a[i]%g[1] == 0)
				ok = 0;
		}
		if(ok){
			cout<<g[1]<<'\n';
			goto out;
		}

		ok = 1;
		for(int i = 1; i < n; i += 2){
			if(a[i]%g[0] == 0)
				ok = 0;
		}
		if(ok){
			cout<<g[0]<<'\n';
			goto out;
		}

		cout<<"0\n";
		out:;
	}
}