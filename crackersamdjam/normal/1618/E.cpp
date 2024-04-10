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
int const MM = 4e4+5;

int t;
ll n, a[MM], b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		ll s = 0;
		for(int i = 0; i < n; i++){
			cin>>b[i];
			s += b[i];
		}
		if((s*2) % (n*(n+1))){
			cout<<"NO\n";
			goto out;
		}
		s = s*2/n/(n+1);
		for(int i = 0; i < n; i++){
			ll d = (b[i]-b[(i+n-1)%n]);
			a[i] = s-d;
			if(a[i]%n or a[i] <= 0){
				cout<<"NO\n";
				goto out;
			}
			a[i] /= n;
		}
		cout<<"YES\n";
		for(int i = 0; i < n; i++)
			cout<<a[i]<<' ';
		cout<<'\n';
		out:;
	}
}