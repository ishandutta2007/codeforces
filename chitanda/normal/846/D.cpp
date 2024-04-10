#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, m, k, q;
int x[510 * 510], y[510 * 510], t[510 * 510];
int s[510][510], tag[510][510], idx;

bool broke(int d){
	++idx;
	for(int i = 1; i <= q; ++i)
		if(t[i] <= d) tag[x[i]][y[i]] = idx;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (tag[i][j] == idx);
			if(i >= k && j >= k && s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k] == k * k)
				return 1;
		}
	return 0;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 1; i <= q; ++i) scanf("%d%d%d", x + i, y + i, t + i);
	int l = -1, r = 1e9 + 1;
	if(!broke(r)){
		printf("-1\n");
		return 0;
	}
	while(l + 1 < r){
		int d = l + ((r - l) >> 1);
		if(broke(d)) r = d;
		else l = d;
	}
	printf("%d\n", r);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}