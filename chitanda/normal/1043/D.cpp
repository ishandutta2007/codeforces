#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

int n, m;
int a[11][100011], p[11][100011];
int cur[11];

inline bool check(int len){
	if(cur[1] + len > n) return 0;
	for(int i = 2; i <= m; ++i)
		if(cur[i] + len > n || a[i][cur[i] + len] != a[1][cur[1] + len]) return 0;
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", a[i] + j), p[i][a[i][j]] = j;

	ll res = 0;
	for(int l = 1, r = 0; l <= n; ++l){
		cur[1] = l;
		for(int i = 2; i <= m; ++i) cur[i] = p[i][a[1][l]];
		r = max(r, l);

		while(check(r - l + 1)) ++r;
		//		printf("%d %d\n", l, r);
		res += r - l + 1;
	}
	printf("%I64d\n", res);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}