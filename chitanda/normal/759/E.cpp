#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

const int maxn = 300100, B = 1e9;
int n;
int a[maxn], b[maxn];
int f[2][maxn], sz[2];
int num[1200];
int len;
char s[10010];

int div(int x){
	if (x == 1) return 0;
	int re = 0;
	for(int i = len - 1; i >= 0; --i){
		ll tmp = (ll)re * B + num[i];
		num[i] = tmp / x;
		re = tmp % x;
	}
	for(; len > 1 && !num[len - 1]; --len);
	return re;
}

int main(){
	//freopen("x.in", "r", stdin);
	//freopen("x.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) scanf("%d", a + i);
	a[1] = 1;
	for(int i = 1; i <= n; ++i) scanf("%d", b + i);
	scanf("%s", s);
	len = strlen(s);
	for(int i = 0; i * 9 < len; ++i){
		int L = i * 9, R = min((i + 1) * 9, len) - 1;
		for(num[i] = 0; L <= R; num[i] = num[i] * 10 + (s[len - 1 - (R--)] - '0'));
	}
	len = (len - 1) / 9 + 1;
	
	int cur = 0, pre = 1;
	f[cur][0] = sz[cur] = 1;

	for(int i = 1; i <= n; ++i){
		int re = div(a[i]);
		//swap(cur, pre);
		sz[pre] = 0;
		for(int j = re; j < sz[cur]; j += a[i], ++sz[pre])
			f[pre][j / a[i]] = f[cur][j];
		sz[cur] = sz[pre] + b[i];
		for(int j = 0, ways = 0; j < sz[cur]; ++j){
			if(j < sz[pre]) ways = (ways + f[pre][j]) % M;
			if(j > b[i]) ways = (ways + M - f[pre][j - b[i] - 1]) % M;
			f[cur][j] = ways;
		}
	}
	printf("%d\n", len == 1 && num[0] < sz[cur] ? f[cur][num[0]] : 0);
	return 0;
}