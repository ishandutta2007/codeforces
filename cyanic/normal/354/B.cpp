
#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int f[maxn*2+5][1<<maxn], n, res;
char str[maxn+5][maxn+5];

int dfs(int k, int s){
	if (f[k][s] < 1e9) return f[k][s];
	int &res = f[k][s], tmp[26], x, y, cnt = 0, Next;
	if (k < 2*n-2){
		memset(tmp, 0, sizeof tmp);
		for (int i=0; i<=k+1; i++){
			x = k+1 - i; y = i;
			if (x >= n || y >= n) continue;
			tmp[str[x][y]-'a'] |= 1 << (cnt++);
		}
		for (int i=0; i<26; i++){
			if (k+1 < n) Next = (s | (s << 1)) & tmp[i];
			else Next = (s | (s >> 1)) & tmp[i];
			if (!Next) continue;
			res = min(res, -dfs(k+1, Next));
		}
	}
	else res = 0;
	for (int i=0; i<=k; i++)
		if (s>>i&1){
			x = min(n-1, k) - i, y = k - x;
			if (str[x][y] == 'a') res += (k&1 ? -1 : 1);
			if (str[x][y] == 'b') res += (k&1 ? 1 : -1);
			break;
		}
	//printf("%d %d %d\n", k, s, res);
	return res;
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<=n-1; i++)
		scanf("%s", str[i]);
	memset(f, 0x3f, sizeof f);
	res = dfs(0, 1);
	if (!res) puts("DRAW");
	else if (res > 0) puts("FIRST");
	else puts("SECOND");
	return 0;
}