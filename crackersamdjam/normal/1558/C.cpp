#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 2500;

int t, n, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		int ok = 1;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			if(a[i]%2 != i%2){
				ok = 0;
			}
		}
		if(!ok){
			cout<<"-1\n";
			continue;
		}
		vector<int> ans;
		auto go = [&](int loc, int &i, int &j){
			// pr("go", loc);
			assert(loc%2);
			if(loc == 1) return;
			reverse(a+1, a+1+loc);
			ans.emplace_back(loc);
			if(i <= loc){
				i = loc-i+1;
			}
			if(j <= loc){
				j = loc-j+1;
			}
			// cerr<<"  "; for(int f = 1; f <= n; f++) cerr<<a[f]<<' '; cerr<<endl;
			return;
		};

		for(int v = 1; v < n; v += 2){
			//look for element v
			int i = 1;
			while(a[i] != v)
				i++;

			int j = 1;
			while(a[j] != v+1)
				j++;

			// pr("v", v, i, j);

			go(i, i, j);
			go(j-1, i, j);
			go(j+1, i, j);
			go(3, i, j);
			go(n-v+1, i, j);
		}
		int z = 0;
		go(n, z, z);

		assert(is_sorted(a+1, a+1+n));
		assert(size(ans) <= n*5/2);
		cout<<size(ans)<<'\n';
		for(int i: ans)
			cout<<i<<' ';
		cout<<'\n';
	}
}