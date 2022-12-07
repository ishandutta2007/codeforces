#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define all(a) a.begin(), a.end()

int n, k, M;
int t[50];
ll f[50][50][50 * 50];

inline void ckmin(ll &a, ll b){
	(a > b) && (a = b);
}

int main(){
	scanf("%d%d%d", &n, &k, &M);
	for(int i = 1; i <= k; ++i)
		scanf("%d", t + i);
	sort(t + 1, t + k + 1);
	
	memset(f, 127, sizeof(f));
	f[1][0][0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= k + 1; ++j)
			for(int l = 0; l <= n * (k + 1); ++l)
				if(f[i][j][l] < 1LL << 60){
					if(j <= k) ckmin(f[i][j + 1][l + 1], f[i][j][l] + t[j + 1]);
					ckmin(f[i + 1][0][l], f[i][j][l]);					
				}
	int x = n * (k + 1);
	while(f[n + 1][0][x] > M) --x;
	printf("%d\n", x);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}