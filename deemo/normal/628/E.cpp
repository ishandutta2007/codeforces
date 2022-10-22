#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<set>

using namespace std;

typedef long long ll;

const int MAXN = 3e3 + 20;

int n, m;
int c[MAXN][MAXN], fen[MAXN][MAXN], ri[MAXN][MAXN], up[MAXN][MAXN];
char ch[MAXN];
ll ans;
vector<pair<int, int>>	st[3 * MAXN];

int get(int c, int r){
	int ret = 0;
	for (; r; r -= r & (-r))
		ret += fen[c][r];
	return	ret;
}

void add(int c, int r, int val){
	for (; r < MAXN; r += r & (-r))
		fen[c][r] += val;
}

int main(){
	scanf("%d %d", &n, &m);
	gets(ch);
	for (int i = 1; i <= n; i++){
		//scanf("%s", ch);
		string temp; gets(ch);
		temp = ch;
		for (int j = 1; j <= m; j++)
			c[i][j] = temp[j - 1] == 'z'?1:0;
	}

	for (int i = 1; i <= n; i++)
		for (int j = m; j; j--)
			if (c[i][j])
				ri[i][j] = ri[i][j + 1] + 1, up[i][j] = up[i - 1][j + 1] + 1;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			if (c[i][j]){
				add(j, i, 1);
				st[i + ri[i][j] - 1].push_back({i, j});
				int go = min(ri[i][j], up[i][j]);
				ans += get(j, i) - get(j, i - go);
			}

		for (pair<int, int>	v:st[i])
			add(v.second, v.first, -1);
	}
	printf("%I64d\n", ans);
	return	0;
}