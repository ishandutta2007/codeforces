#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, x;
map<int, vector<int> > mp;
map<vector<int>, int> nim;

int solve(vector<int> vec){
	if(!vec.size()) return 0;
	if(nim.count(vec)) return nim[vec];
	int n = vec.size();
	vector<int> mex;
	for(int i = 1; i <= vec[n - 1]; ++i){
		vector<int> vv;
		for(int j = 0; j < n; ++j)
			if(vec[j] > i) vv.pb(vec[j] - i);
			else if(vec[j] < i) vv.pb(vec[j]);
		sort(all(vv));
		vv.erase(unique(all(vv)), vv.end());		
		mex.pb(solve(vv));
	}
	sort(all(mex));
	mex.erase(unique(all(mex)), mex.end());
	int sg = 0;
	while(sg < mex.size() && mex[sg] == sg) ++sg;
	return nim[vec] = sg;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		int lim = sqrt(x) + 0.1;
		for(int i = 2; i <= lim; ++i)
			if(x % i == 0){
				int tmp = 0;
				while(x % i == 0) ++tmp, x /= i;
				mp[i].pb(tmp);
			}
		if(x > 1) mp[x].pb(1);
	}
	int res = 0;
	for(auto v : mp){
		auto vec = v.se;
		sort(all(vec));
		vec.erase(unique(all(vec)), vec.end());
		res ^= solve(vec);
	}
	printf("%s\n", res ? "Mojtaba" : "Arpa");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}