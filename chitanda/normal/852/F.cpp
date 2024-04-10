#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, a, Q;
int pw[1001000];
int X;
int fac[1001000], inv[1001000];
int ans[1001000];

int C(int n, int m){
	return (ll)fac[n] * inv[m] % X * inv[n - m] % X;
}

int main(){
	scanf("%d%d%d%d", &N, &M, &a, &Q);
	X = 1;
	pw[0] = 1, pw[1] = a;
	while(pw[X] != 1) pw[X + 1] = (ll)pw[X] * a % Q, ++X;
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for(int i = 2; i <= M; ++i){
		fac[i] = (ll)fac[i - 1] * i % X;
		inv[i] = (ll)(X - X / i) * inv[X % i] % X;
	}
	for(int i = 2; i <= M; ++i)
		inv[i] = (ll)inv[i - 1] * inv[i] % X;
	
	int cnt = 0;
	for(int i = 0; i < N; ++i){
		cnt += i <= M ? C(M, i) : 0;
		cnt %= X;
		ans[N - i - 1] = pw[cnt];
	}
	for(int i = 0; i < N; ++i)
		printf("%d ", ans[i]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}