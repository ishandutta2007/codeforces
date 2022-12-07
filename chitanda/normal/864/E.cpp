#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 111;
int n;
int w[maxn], t[maxn], d[maxn], p[maxn];
int f[maxn][2017], last[maxn][2017];
vector<int> bag;

void work(int i, int j){
	if(!last[i][j]) return;
	work(last[i][j] - 1, j - t[w[last[i][j]]]);
	bag.pb(w[last[i][j]]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", t + i, d + i, p + i), w[i] = i;
	sort(w + 1, w + n + 1, [](int i, int j) { return d[i] < d[j]; });
	memset(f, 128, sizeof(128));
	f[0][0] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= 2000; ++j)
			f[i][j] = f[i - 1][j], last[i][j] = last[i - 1][j];
		for(int j = 0; j < d[w[i]] - t[w[i]]; ++j)
			if(f[i - 1][j] + p[w[i]] > f[i][j + t[w[i]]]){
				f[i][j + t[w[i]]] = f[i - 1][j] + p[w[i]];
				last[i][j + t[w[i]]] = i;
			}
	}	
	int ans = -1, la;
	for(int i = 0; i <= 2000; ++i)
		if(f[n][i] > ans) ans = f[n][i], la = i;

	printf("%d\n", ans);	
	work(n, la);
	printf("%d\n", (int)bag.size());
	for(int v : bag)
		printf("%d ", v);
 
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}