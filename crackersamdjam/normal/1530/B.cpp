#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int a[30][30];

bool ok(int x, int y){
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(a[x+i][y+j])
				return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; i += 2){
			a[i][1] = 1;
		}
		for(int i = 1; i <= m; i += 2){
			a[1][i] = 1;
		}

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(i == n or j == m)
					a[i][j] |= ok(i, j);
				cout<<a[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
}