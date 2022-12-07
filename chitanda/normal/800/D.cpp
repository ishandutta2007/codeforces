#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int N = 1000000;
int n;
int a[N + 1];
int cnt[N][3];
int f[N];
int two[N], ten[6];

inline void add(int &a, int b){
	a += b;
	if(a >= M) a -= M;
	if(a < 0) a += M;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		add(cnt[a[i]][0], 1);
		add(cnt[a[i]][1], a[i]);
		add(cnt[a[i]][2], (ll)a[i] * a[i] % M);
	}

	two[0] = ten[0] = 1;
	for(int i = 1; i < 6; ++i) ten[i] = ten[i - 1] * 10;
	for(int i = 1; i < N; ++i) two[i] = two[i - 1] * 2 % M;

	for(int i = 0; i < 6; ++i)
		for(int j = N - 1; j >= 0; --j)
			if(j / ten[i] % 10)
				for(int k = 0; k < 3; ++k)
					add(cnt[j - ten[i]][k], cnt[j][k]);
	
	for(int i = 0; i < N; ++i){
		int tmp = ((ll)cnt[i][1] * cnt[i][1] % M - cnt[i][2] + M) % M;
		if(cnt[i][0] >= 2) add(f[i], (ll)tmp * two[cnt[i][0] - 2] % M);
		if(cnt[i][0]) add(f[i], (ll)cnt[i][2] * two[cnt[i][0] - 1] % M);
	}

	for(int i = 0; i < 6; ++i)
		for(int j = 0; j < N; ++j)
			if(j / ten[i] % 10)
				add(f[j - ten[i]], -f[j]);

	ll ans = 0;
	for(int i = 0; i < N; ++i)
		ans ^= (ll)f[i] * i;
	printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}