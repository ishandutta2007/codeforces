#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 105;

int n, k, a[MM*MM];
int ok[MM*MM];
int done[MM];
pair<int, int> ans[MM];
int pre[MM];

void recalc(){
	// called at most n times

	for(int i = 1; i <= n; i++){
		pre[i] = 0;
	}

	for(int i = 1; i <= n*k; i++){
		ok[i] = 0;
	}

	int last = 0;
	for(int i = 1; i <= n*k; i++){
		if(done[a[i]])
			continue;
		if(pre[a[i]] > last){
			ok[pre[a[i]]] = i;
			last = pre[a[i]];
		}
		pre[a[i]] = i;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>k;
	for(int i = 1; i <= n*k; i++){
		cin>>a[i];
	}
	int lim = (n + (k-1)-1)/(k-1);
	recalc();

	for(int t = 0; t < lim; t++){
		int i = 1;
		while(i <= n*k){
			if(ok[i] and !done[a[i]]){
				// assert(!done[a[i]]);
				done[a[i]] = 1;
				// ans.emplace_back(i, ok[i]);
				ans[a[i]] = {i, ok[i]};
				i = ok[i];
				recalc();
			}
			i++;
		}
	}

	for(int i = 1; i <= n; i++){
		assert(ans[i].first);
		assert(a[ans[i].first] == a[ans[i].second]);
		assert(a[ans[i].first] == i);
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
}