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
int a[2600];
int f[100100];

int inv(int a){
	return a == 1 ? 1 : (ll)(M - M / a) * inv(M % a) % M;
}

int UP(int x){
	return x < 0 ? x + M : x;
}

int main(){
	scanf("%d", &n);
	ll sum = 0;
	int tmax = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		sum += a[i];
		tmax = max(a[i], tmax);
	}

	f[1] = (ll)(sum - 1) * (sum - 1) % M * inv(sum) % M;
	for(int i = 1; i < tmax; ++i)
		f[i + 1] = UP((2LL * f[i] - f[i - 1] - (ll)(sum - 1) * inv(sum - i)) % M);

	int res = 0;
	for(int i = 0; i < n; ++i)
		res = (res + f[a[i]]) % M;
	
	printf("%d\n", res);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}