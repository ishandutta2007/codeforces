#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 105;

int t;
char c[MM][MM];
// char cc[MM*MM];

char val(int i, int j, int o){
	if(o == 0){
		//horizontal
		return 'a' + (i*3 + j/2) % 9;
	}
	else{
		return 'k' + (i/2*3 + j) % 9;
	}
}

int run(int n, int m, int k){
	int id = 0;
	if(n%2){
		k -= m/2;
		for(int i = 0; i < m; i += 2){
			c[n-1][i] = c[n-1][i+1] = val(n-1, i, 0);
		}
		n--;
	}
	if(m%2){
		for(int i = 0; i < n; i += 2){
			c[i][m-1] = c[i+1][m-1] = val(i, m-1, 1);
		}
		m--;
	}
	for(int i = 0; i < n; i += 2){
		for(int j = 0; j < m; j += 2){
			if(k >= 2){
				k -= 2;
				c[i][j] = c[i][j+1] = val(i, j, 0);
				c[i+1][j] = c[i+1][j+1] = val(i+1, j, 0);
			}
			else{
				c[i][j] = c[i+1][j] = val(i, j, 1);
				c[i][j+1] = c[i+1][j+1] = val(i, j+1, 1);
			}
		}
	}

	return k;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		if(run(n, m, k)){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++)
					cout<<c[i][j];
				cout<<'\n';
			}
		}
	}			
}