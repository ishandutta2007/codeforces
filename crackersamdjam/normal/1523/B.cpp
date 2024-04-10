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

int t, n;
ll a[MM];

void go(int o, int l, int r){
	cout<<o<<' '<<l<<' '<<r<<'\n';
	if(o == 1){
		a[l] += a[r];
	}
	else{
		a[r] -= a[l];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
		}
		cout<<n/2*6<<'\n';
		for(int i = 1; i <= n; i += 2){
			go(1, i, i+1);
			go(2, i, i+1);
			go(1, i, i+1);
			go(1, i, i+1);
			go(2, i, i+1);
			go(1, i, i+1);
		}
		// for(int i = 1; i <= n; i++)
			// cout<<a[i]<<' ';
		// cout<<endl;
	}
}