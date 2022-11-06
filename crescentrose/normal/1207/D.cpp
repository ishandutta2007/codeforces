#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int mod = 998244353;
long long ans;
int n;
long long s[1000001];
int a[1000000][2], b[1000000], d[1000001];
int main(){
	scanf("%d", &n);
	s[0] = 1;
	for (int i = 1;i <= n ; i ++)
		s[i] = s[i - 1] * i % mod;
	for (int i = 1; i <= n ; i ++){
		scanf("%d %d", &a[i][0], &a[i][1]);
		b[i]= a[i][0];
		d[i ] = i;
	}
	long long v = 1;
	sort(b + 1, b + n + 1);
	int  l =1;
	for (int i = 2; i <= n ; i++)
		if (b[l] != b[i]) {
			v = v * s[i - l] % mod;
			l = i;
		}
	v = v * s[n - l + 1] % mod;
	ans = v;
    v = 1;
	for (int i = 1; i <= n;  i++)
		b[i] = a[i][1];
	sort(b + 1, b + n + 1);
	l =1;
	for (int i = 2; i <= n ; i++)
		if (b[l] != b[i]) {
			v = v * s[i - l] % mod;
			l = i;
		}
	v = v * s[n - l + 1] % mod;
	ans = (ans + v) % mod;
	sort(d +1, d+ n+1,[](int x, int y) {return a[x][0] < a[y][0] || (a[x][0] == a[y][0] && a[x][1] < a[y][1]);});
	v = 1;
	l = 1;
	for (int i = 2; i <= n ; i++){
		if (a[d[i]][1] < a[d[l]][1]) {
			printf("%d\n",( s[n] - ans + mod)%mod);
			return 0;
		}
		if (a[d[l]][0] != a[d[i]][0] || a[d[l]][1] != a[d[i]][1]) {
			v = v * s[i - l] % mod;
			l = i;
		}
	}
	v = v * s[n - l  + 1] % mod;
	printf("%d\n", (s[n] - (ans -v+mod) % mod + mod) % mod);
	return 0;
}