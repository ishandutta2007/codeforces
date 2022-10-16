#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 2e5+5;

int t, n, a[MM], to[MM], from[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			if(!from[a[i]]){
				to[i] = a[i];
				from[a[i]] = i;
			}
		}
		vector<int> va, vb;
		for(int i = 1; i <= n; i++){
			if(!to[i]){
				va.emplace_back(i);
			}
			if(!from[i]){
				vb.emplace_back(i);
			}
		}
		assert(size(va) == size(vb));

		if(size(va) == 1 and va[0] == vb[0]){
			int cur = va[0];
			to[cur] = a[cur];
			int o = from[a[cur]];
			to[o] = cur;
		}
		else if(size(va)){
			if(va[0] == vb[0])
				swap(va[0], va[1]);
			for(int i = 1; i < size(va); i++){
				if(va[i] == vb[i])
					swap(va[i], va[i-1]);
			}
			for(int i = 0; i < size(va); i++){
				assert(va[i] != vb[i]);
				to[va[i]] = vb[i];
			}
		}

		int ans = 0;
		for(int i = 1; i <= n; i++){
			assert(to[i] != i);
			ans += to[i] == a[i];
		}
		cout<<ans<<'\n';

		for(int i = 1; i <= n; i++){
			cout<<to[i]<<' ';
			a[i] = to[i] = from[i] = 0;
		}
		cout<<'\n';
	}
}