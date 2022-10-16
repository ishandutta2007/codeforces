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

int t, n;
ll a[MM];

int run(){
	set<ll> st;
	vector<ll> v;
	for(int i = 0; i < n; i++){
		st.insert(a[i]);
		if(a[i]) v.emplace_back(a[i]);
	}
	sort(a, a+n);

	bool ok = 1;
	ok &= st.count(a[0]+a[1]+a[2]);
	ok &= st.count(a[n-3]+a[n-2]+a[n-1]);
	if(n > 3 and a[0] and a[n-1] and a[0] != -a[n-1]){
		ok = 0;
	}
	// pr(a[0]+a[1]+a[2], a[n-3]+a[n-2]+a[n-1]);
	return ok;
}

int run2(){
	set<ll> st;
	for(int i = 0; i < n; i++){
		st.insert(a[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){
				if(!st.count(a[i]+a[j]+a[k])){
					return 0;
				}
			}
		}
	}

	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		int ans;
		if(n <= 10){
			ans = run2();
		}
		else{
			ans = run();
		}
		cout<<(ans?"YES\n":"NO\n");
		// if(n > 10 and run() != run2()){
		// 	pr(1);
		// 	pr(n);
		// 	for(int i = 0; i < n; i++)
		// 		cerr<<a[i]<<' ';
		// 	cerr<<endl;
		// 	abort();
		// }
	}
}