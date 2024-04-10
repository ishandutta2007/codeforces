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

int t, n, a[2][MM], b[2][MM], c[2][MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>a[0][i];
			a[0][i]++;
		}
		for(int i = 0; i < n; i++){
			cin>>a[1][i];
			a[1][i]++;
		}
		a[0][0]--;

		b[0][n] = b[1][n] = -2e9;
		c[0][n] = c[1][n] = -2e9;
		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j < 2; j++){
				b[j][i] = max(b[j][i+1], a[j][i]-i);
				c[j][i] = max(c[j][i+1], a[j][i]+i);
			}
		}

		// for(int i = 0; i < n; i++)
		// 	cerr<<b[0][i]<<' ';
		// cerr<<endl;
		// for(int i = 0; i < n; i++)
		// 	cerr<<b[1][i]<<' ';
		// cerr<<endl;
		// cerr<<endl;
		// for(int i = 0; i < n; i++)
		// 	cerr<<c[0][i]<<' ';
		// cerr<<endl;
		// for(int i = 0; i < n; i++)
		// 	cerr<<c[1][i]<<' ';
		// cerr<<endl;
		// cerr<<endl;

		int tot = 2*n-1;

		int ans = 2e9, cur = 0, s = 0;
		for(int i = 0; i < n; i++){
			int val = max({cur, b[s][i]+n-1 -(n-1) - i, c[!s][i]-(n-1) - 2*i - (n-1-i) - 1});
			// pr("i", i, s, val+tot, val, "=", cur, b[s][i] - 2*i, c[!s][i]-(n-1) - 2*i - (n-1-i) - 1);
			ans = min(ans, val);
			cur = max({cur, a[s][i] - 2*i, a[!s][i] - 2*i-1});
			s ^= 1;
		}

		cout<<ans+tot<<'\n';
		// pr("ans", ans+tot, ans);
		// pr("");
	}
}