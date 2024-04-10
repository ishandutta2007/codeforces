#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define pb(x) push_back(x)
const int max_n = 1e5;

int n, q;
vector<int>	vec, sec[max_n + 20], gec;

bool ok(int x, int l, int r){
	int t = upper_bound(sec[x].begin(), sec[x].end(), r) - lower_bound(sec[x].begin(), sec[x].end(), l);
	return	t == x;
}

int main(){
	scanf("%d%d", &n, &q);
	vec.resize(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		if (vec[i] > max_n)	continue;
		sec[vec[i]].pb(i);
	}
	for (int i = 1; i <= max_n; i++)
		if (sec[i].size() >= i)
			gec.pb(i);
	
	while (q--){
		int l, r;	scanf("%d%d", &l, &r);	l--, r--;
		int ans = 0;
		for (int i = 0; i < gec.size(); i++)
			if (ok(gec[i], l, r))
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}