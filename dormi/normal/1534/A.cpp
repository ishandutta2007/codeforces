#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 55;

int t, n, m;
string s[MM];
char cc[] = {'R', 'W'};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> r(2), w(2);
		for(int i = 0; i < n; i++){
			cin>>s[i];
			for(int j = 0; j < m; j++){
				if(s[i][j] == 'R')
					r[i+j&1] = 1;
				else if(s[i][j] == 'W')
					w[i+j&1] = 1;
			}
		}
		int v = r[1] or w[0];
		int vv = r[0] or w[1];
		if(v and vv){
			cout<<"NO\n";
			continue;
		}

		cout<<"YES\n";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				char c = cc[i+j+v&1];
				cout<<c;
				if(s[i][j] != '.')
					assert(s[i][j] == c);
			}
			cout<<'\n';
		}
	}
}