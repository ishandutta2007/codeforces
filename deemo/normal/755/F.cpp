//Let's get together maybe we can start a new phase..
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, k, p[MAXN], cv, cnt[MAXN];
bool vis[MAXN];

void dfs(int v){
	vis[v] = 1;
	cv++;
	if (!vis[p[v]])
		dfs(p[v]);
}

bitset<MAXN> can;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;
	int c1, c2;
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			cv = 0;
			dfs(i);
			cnt[cv]++;
			c2 += cv>>1;
			c1 += cv&1;
		}

	for (int i = 1; i < n; i++)
		if (cnt[i]){
			int t = cnt[i]-1>>1;
			cnt[i<<1]+=t;
			cnt[i]&=1;
			if (!cnt[i]) cnt[i]=2;
		}

	can[0] = 1;
	for (int i = 1; i <= n; i++)
		while (cnt[i]--)
			can |= can<<i;

	if (can[k])
		cout << k << " ";
	else
		cout << k+1 << " ";

	{
		int ret=min(k, c2)*2;
		k -= min(k, c2);
		ret += min(k, c1);
		cout << ret << "\n";
	}
	
	return 0;
}