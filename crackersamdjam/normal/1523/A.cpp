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
const int MM = 1005;

int t, n, m;
ll l[MM], r[MM];
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(l, 0x3f, sizeof l);
		memset(r, 0x3f, sizeof r);
		cin>>s;
		s = " "+s;
		for(int i = 1; i <= n; i++){
			l[i] = l[i-1]+1;
			if(s[i] == '1')
				l[i] = 0;
		}
		for(int i = n; i; i--){
			r[i] = r[i+1]+1;
			if(s[i] == '1')
				r[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			int ok = (s[i] == '1');
			if(l[i] != r[i] and min(l[i], r[i]) <= m)
				ok = 1;

			cout<<ok;
		}
		cout<<'\n';
	}
}