#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
char s[1 << 21];
int f[1 << 20];
int c[1 << 20];

void FWT(int x[], int l, int r, int v){
	if(l == r) return;
	int m = (l + r) >> 1;
	FWT(x, l, m, v), FWT(x, m + 1, r, v);
	for(int i = 0; i <= m - l; ++i){
		(x[l + i] += x[m + 1 + i]) %= M;
		x[m + 1 + i] = ((x[l + i] - 2LL * x[m + 1 + i]) % M + M) % M;
		if(v < 0) x[l + i] = (x[l + i] * 500000004LL) % M, x[m + 1 + i] = (x[m + 1 + i] * 500000004LL) % M; //xor
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < 1 << n; ++i){
		f[i] = s[i] - '0';
		c[i] = n - __builtin_popcount(i);
	}
	FWT(f, 0, (1 << n) - 1, 1);
	for(int i = 0; i < 1 << n; ++i)
		f[i] = (ll)f[i] * f[i] % M;
	FWT(f, 0, (1 << n) - 1, -1);


	int res = 0;
	for(int i = 0; i < (1 << n); ++i)
		res = (res + (ll)f[i] * (1 << c[i])) % M;
	res = res * 3LL % M;
	printf("%d\n", res);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}