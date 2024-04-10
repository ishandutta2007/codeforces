#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int XX = 1e7 + 10;
const int MAXN = 20 + 2;

int n, m, k, sz, vec[XX], mp[XX];
int adj[MAXN], w[MAXN][MAXN], ms;

void gen(int cur = 0, int sm = 0){
	vec[sz++] = sm;
	if (cur == n)	return;

	for (; cur < n; cur++){
		int z = adj[cur];
		while (z){
			int id = mp[z&-z];
			z-=z&-z;
			if ((ms>>id)&1)	continue;
			ms ^= 1<<id;
			gen(cur + 1, sm + w[cur][id]);
			ms ^= 1<<id;
		}
	}
}

int main(){
	for (int i = 0; i < MAXN; i++)
		mp[1<<i] = i;
	cin >> n >> m >> k;
	while (m--){
		int a, b, c;	cin >> a >> b >> c, a--, b--;
		w[a][b] = c;
		adj[a] |= 1<<b;
	}
	gen();
	sort(vec, vec + sz);
	cout << vec[k - 1] << endl;
	return 0;
}