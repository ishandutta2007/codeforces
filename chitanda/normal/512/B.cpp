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

const int inf = 1e9;
map<int, int> mp[310];
int n;
int l[310];
int c[310];

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

int dp(int t, int v){
	if(v == 1) return 0;
	if(t == n + 1) return inf;
	if(mp[t].count(v)) return mp[t][v];
	return mp[t][v] = min(dp(t + 1, v), dp(t + 1, gcd(v, l[t])) + c[t]);
}

int main(){
	scanf("%d", &n);
	int g = 0;
	for(int i = 1; i <= n; ++i) scanf("%d", l + i), g = gcd(g, l[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", c + i);
	if(g != 1) puts("-1");
	else{
		printf("%d\n", dp(1, 0));
	}
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}