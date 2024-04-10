#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, k;
int f[2][4010];
pair<pair<int, int>, int> sta[4010];
int u[4010][4010], s[4010][4010], cost[4010][4010];

inline int calc(int pre, int l, int r){
	return f[pre][l] < 1e9 ? f[pre][l] + cost[l + 1][r] : 1e9;
}

void read(int &n){
	static char c;
	c = getchar();
	while(c < '0' || c > '9') c = getchar();
	n = 0;
	while(c >= '0' && c <= '9') n = n * 10 + c - '0', c = getchar();	
}

int main(){
	read(n); read(k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			read(u[i][j]);
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + u[i][j];
		}
	
	for(int l = 1; l <= n; ++l)
		for(int r = l; r <= n; ++r){
			cost[l][r] = (s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1]) / 2;
		}
	
	memset(f, 127, sizeof(f));
	f[0][0] = 0;
	int pre = 0, now = 1;
	for(int i = 1; i <= k; ++i){
		memset(f[now], 127, sizeof(int) * (n + 1));
		sta[1] = mkp(mkp(1, n), 0);
		int l = 1, r = 1;
		for(int j = 1; j <= n; ++j){
			f[now][j] = calc(pre, sta[l].se, j);
			if(sta[l].fi.fi == j) sta[l].fi.fi++;
			if(sta[l].fi.fi > sta[l].fi.se) ++l;
			if(j == n) continue;
			if(l > r){
				sta[++r] = mkp(mkp(j + 1, n), j);
				continue;
			}
			if(calc(pre, j, n) >= calc(pre, sta[r].se, n)) continue;
			while(l <= r && calc(pre, sta[r].se, sta[r].fi.fi) >= calc(pre, j, sta[r].fi.fi)) --r;
			if(l > r) sta[++r] = mkp(mkp(j + 1, n), j);
			else{
				int lt = sta[r].fi.fi, rt = sta[r].fi.se + 1;
				while(lt + 1 < rt){
					int d = (lt + rt) >> 1;
					if(calc(pre, sta[r].se, d) < calc(pre, j, d)) lt = d;
					else rt = d;
				}
				sta[r].fi.se = lt;
				sta[++r] = mkp(mkp(rt, n), j);
			}
		}
		swap(pre, now);
	}
	printf("%d\n", f[pre][n]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}