#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a, b, n, ans;
map<LL,int> f[105];

inline LL power(LL x, LL p){
	LL res = 1;
	while (p){
		if (p&1) res *= x;
		x *= x; p >>= 1;
	}
	return res;
}

int dfs(LL a, LL b){
	if (power(a, b) >= n) return 1;
	if (f[b].count(a)) return f[b][a];
	if (a == 1 && power(2, b) >= n) return -1;
	if (b == 1 && a*a >= n) return 1-((n-a)&1);
	return f[b][a] = !dfs(a+1, b) || !dfs(a, b+1);
}

int main(){
	scanf("%I64d%I64d%I64d", &a, &b, &n);
	ans = dfs(a, b);
	if (ans == 1) puts("Masha");
	else if (ans == 0) puts("Stas");
	else puts("Missing");
	return 0;
}