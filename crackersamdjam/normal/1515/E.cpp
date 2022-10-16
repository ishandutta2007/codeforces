#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 405;

ll n, m, ans, p2[MM];

void add(ll &a, ll b){
	a += b;
	a %= m;
}

ll C[MM][MM];
ll dp[MM][MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin>>n>>m;

	p2[0] = 1;
	for(int i = 1; i < MM; i++){
		p2[i] = p2[i-1]*2%m;
	}

	C[0][0] = 1;
	for(int i = 1; i < MM; i++){
		C[i][0] = 1;
		for(int j = 1; j < MM; j++){
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%m;
		}
	}
	
	for(int i = 1; i <= n; i++){
		dp[i][i] = p2[i-1];
		//new segment

		for(int k = 1; k <= n; k++){
			for(int j = 1; j < i-1; j++){
				//j -- i
				// j+1 is empty one that gets turned on
				int len = i-j-1;
				if(k-len >= 0){
					add(dp[i][k], dp[j][k-len]*p2[len-1] % m * C[k][len]);
				}
			}
			// cerr<<dp[i][k]<<' ';
		}
		// cerr<<endl;
	}

	for(int i = 1; i <= n; i++){
		add(ans, dp[n][i] % m);
	}
	cout<<ans<<'\n';
}
/*
1, 2, 6, 20, 78, 344, 
*/