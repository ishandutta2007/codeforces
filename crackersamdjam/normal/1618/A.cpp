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



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		vector<ll> b(7);
		for(auto &x: b)
			cin>>x;
		sort(all(b));
		auto bb = b;
		do{
			vector<ll> a;
			for(int i = 1; i <= 7; i++){
				ll s = 0;
				for(int j = 0; j < 3; j++){
					if((i>>j)&1)
						s += b[j];
				}
				a.emplace_back(s);
			}
			sort(all(a));
			if(a == bb){
				cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<'\n';
				break;
			}
		} while(next_permutation(all(b)));
	}
}