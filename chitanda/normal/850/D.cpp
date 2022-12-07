#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

bool f[65][35][2000];
int m;
int a[35];
int d[65], w[65];
int b[65][65];

bool inline ok(int n){
	return f[n][m][n * (n - 1) / 2];
}

void get(int n, int m, int s){
	if(!n) return;
	d[n] = a[m];
	if(f[n - 1][m][s - a[m]]) get(n - 1, m, s - a[m]);
	else get(n - 1, m - 1, s - a[m]);
}

int main(){
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + m + 1);
 
	f[1][1][a[1]] = 1;
	int n = 1;
	
	while(n < 61 && !ok(n)){
		for(int i = 1; i <= m; ++i)
			for(int j = n * (n - 1) / 2; j <= n * a[m]; ++j)
				if(f[n][i][j]){
					f[n + 1][i][j + a[i]] = 1;
					f[n + 1][i + 1][j + a[i + 1]] = 1;
				}
		++n;
	}
	
	if(!ok(n)){
		puts("=(");
		return 0;
	}

	get(n, m, n * (n - 1) / 2);
	
	for(int i = n; i > 1; --i){
		vector<pair<int, int> > q;
		for(int j = 1; j < i; ++j) w[j] = j;
		sort(w + 1, w + i, [](int i, int j) { return d[i] < d[j]; });
		for(int j = 1; j <= d[i]; ++j)
			b[i][w[j]] = 1;		
		for(int j = d[i] + 1; j < i; ++j)
			b[w[j]][i] = 1, --d[w[j]];
	}

	printf("%d\n", n);
	for(int i = 1; i <= n; puts(""), ++i)
		for(int j = 1; j <= n; ++j)
			putchar('0' + b[i][j]);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}