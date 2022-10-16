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
int const MM = 305;

int n, m;
bool taken[MM][MM];
array<int, 2> a[MM*MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(taken, 0, sizeof taken);
		for(int i = 0; i < n*m; i++){
			cin>>a[i][0];
			a[i][1] = i;
		}
		sort(a, a+n*m, [](auto x, auto y){
			if(x[0] != y[0])
				return x[0] < y[0];
			return x[1] > y[1];
		});
		for(int i = 0; i < n*m; i++){
			a[i][0] = i;
		}
		sort(a, a+n*m, [](auto x, auto y){
			return x[1] < y[1];
		});
		int ans = 0;
		for(int i = 0; i < n*m; i++){
			taken[0][a[i][0]] = 1;
			for(int j = 0; j < a[i][0]; j++){
				ans += taken[0][j];
			}
		}
		cout<<ans<<'\n';
	}
}