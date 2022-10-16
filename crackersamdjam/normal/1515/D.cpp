#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 2e5+5;

int n, l, r, t, a[MM], b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		int ans = 0;
		int lsz = l, rsz = r;

		for(int i = 0,c; i < l; i++){
			cin>>c;
			a[c]++;
		}
		for(int i = 0,c; i < r; i++){
			cin>>c;
			b[c]++;
			if(a[c] and b[c]){
				a[c]--;
				b[c]--;
				lsz--;
				rsz--;
			}
		}

		//wlog ls is larger
		if(l < r){
			swap(l, r);
			swap(a, b);
			swap(lsz, rsz);
		}

		ans += rsz;
		// they change colour

		int rem = (l-r)/2;
		//pairs to match
		for(int i = 1; i <= n; i++){
			while(rem > 0 and a[i] >= 2){
				a[i] -= 2;
				rem--;
				ans++;
				lsz -= 2;
			}
		}

		lsz -= rsz;
		ans += lsz;
		//unmatched

		cout<<ans<<'\n';

		for(int i = 1; i <= n; i++){
			a[i] = b[i] = 0;
		}
	}
}