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

int t, n, a[MM][MM], par[MM];

int find(int x){
	if(x < 0) return -find(-x);
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x < 0) x = -x, y = -y;
	if(x != -y)
		par[x] = y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin>>a[i][j];
			}
		}
		iota(par, par+n+1, 0);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j] < a[j][i]){
					merge(i, j);
				}
				else if(a[i][j] > a[j][i]){
					merge(i, -j);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(find(i) > 0){
				for(int j = 1; j <= n; j++){
					swap(a[i][j], a[j][i]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				cout<<a[i][j]<<' ';
			cout<<'\n';
		}
	}
}