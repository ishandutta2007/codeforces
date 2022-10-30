#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
typedef long long LL;
const int mod = 1e9 + 7;
 
int n, b[2 * maxn], a[maxn];
char s[maxn];
int getans(){
	memset(b, 0, sizeof b);
	int mn = mod;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		cnt += a[i];
		mn = min(mn, cnt);
		b[cnt + maxn]++;
	}
	return b[mn + maxn];
}
 
int main(){
	scanf("%d", &n);
	scanf(" %s", s + 1);
	int ok = 0;
	for(int i = 1; i <= n; ++i){
		a[i] = (s[i] == '(' ? 1 : -1);
		ok += (s[i] == '(' ? 1 : -1);
	}
	if(ok != 0){
		printf("0\n1 1\n");
		return 0;
	}
	int res = -1, ans = -1, l, r;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			swap(a[i], a[j]);
			res = getans();
			if(ans < res){
				ans = res;
				l = i, r = j;
			}
			swap(a[i], a[j]);
		}
	}
	printf("%d\n%d %d\n", ans, l, r);
	return 0;
}