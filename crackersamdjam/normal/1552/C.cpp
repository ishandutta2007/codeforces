#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int t, n, k;
int vis[205];
int done[205], in[205];

int count(int l, int r){
	memset(in, 0, sizeof in);
	if(l > r) swap(l, r);
	int cnt = 0;
	for(int i = l; i <= r; i++){
		if(done[i]){
			if(in[done[i]]){
				in[done[i]] = 0;
				cnt--;
			}
			else{
				in[done[i]] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>k;
		memset(done, 0, sizeof done);
		int ans = 0;

		for(int i = 1,a,b; i <= k; i++){
			cin>>a>>b;
			ans += count(a, b);
			done[a] = done[b] = i;
		}

		int rem = n-k;
		ans += rem*(rem-1)/2;

		vector<int> v;

		for(int i = 1; i <= 2*n; i++){
			if(!done[i]){
				v.emplace_back(i);
			}
		}

		for(int i = 0; i < rem; i++){
			int c = count(v[i], v[i+rem]);
			ans += c;
		}
		cout<<ans<<'\n';
	}
}