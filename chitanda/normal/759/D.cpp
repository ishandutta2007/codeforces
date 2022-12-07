#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long

const int maxn = 5010;
int n;
int f[maxn][maxn], la[26], C[maxn][maxn];
char s[maxn];

int main(){
	//freopen("x.in", "r", stdin);
	//freopen("x.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 0; i <= n; C[i++][0] = 1)
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < i; ++j) f[i][j] = f[i - 1][j];
		for(int j = 1; j <= i; ++j){
			f[i][j] = (f[i][j] + f[i - 1][j - 1]) % M;
			if(la[s[i] - 'a']) f[i][j] = (f[i][j] + M - f[la[s[i] - 'a']][j - 1]) % M;
		}
		la[s[i] - 'a'] = i;
	}
	int res = 0;
	for(int i = 1; i <= n; ++i) res = (res + (ll)f[n][i] * C[n - 1][i - 1]) % M;
	printf("%d\n", res);
	return 0;
}