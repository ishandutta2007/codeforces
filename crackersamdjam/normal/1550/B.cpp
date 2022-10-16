#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int t, n, a, b;
string s;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>a>>b>>s;
		int cnt = 1;
		for(int i = 1; i < n; i++){
			if(s[i] != s[i-1])
				cnt++;
		}
		if(b > 0){
			cout<<a*n+b*n<<'\n';
		}
		else{
			cnt = (cnt)/2+1;
			cout<<a*n+b*cnt<<'\n';
		}
	}			
}