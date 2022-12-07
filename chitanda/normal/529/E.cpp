#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 5
#define all(a) a.begin(), a.end()

const int inf = 1e9;
int n, k, m, x;
int a[5011];
map<int, int> mp;

int main(){
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		for(int j = 1; j <= k; ++j)
			if(a[i] * j < x && mp.count(a[i] * j))
				mp[a[i] * j] = min(mp[a[i] * j], j);
			else mp[a[i] * j] = j;
	}
	
	scanf("%d", &m);
	while(m--){
		scanf("%d", &x);
		int ans = mp.count(x) ? mp[x] : inf;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= k; ++j)
				if(mp.count(x - a[i] * j))
					ans = min(mp[x - a[i] * j] + j, ans);
		if(ans <= k) printf("%d\n", ans);
		else printf("-1\n");
	}
	
	return 0;
}