#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int t, n, x, a[105];
	cin>>t;
	while(t--){
		cin>>n>>x;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		sort(a, a+n);

		int sum = 0;
		int ok = 1, bad = 0;
		for(int i = 0; i < n; i++){
			sum += a[i];
			if(sum == x){
				ok = 0;
				bad = i;
			}
		}

		if(!ok){
			if(x == sum){
				cout<<"NO\n";
				continue;
			}
			swap(a[bad], a[bad+1]);
		}
		cout<<"YES\n";
		for(int i = 0; i < n; i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
}