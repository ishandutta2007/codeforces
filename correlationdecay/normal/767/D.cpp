#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <cmath>
#include <iostream>
#define maxn 2000009
using namespace std;
int n, m, k;
int f[maxn];
int a[maxn];
struct Milk{
	int s, id;
	bool operator < (const Milk &rhs) const{
		return s > rhs.s;
	}
}g[maxn];
bool cmp(int x, int y){
	return x > y;
}
bool check(int m){
	int tot = 0;
	int p = 1, q = 1;
	while(p <= n || q <= m){
		if(p > n){
			a[++tot] = g[q].s;
			q++;
			continue;
		}
		if(q > m){
			a[++tot] = f[p];
			p++;
			continue;
		}
		if(g[q].s > f[p]){
			a[++tot] = g[q].s;
			q++;
		}
		else{
			a[++tot] = f[p];
			p++;
		}
	}
	/*
	for(int i = 1; i <= tot; i++){
		cout << a[i] << endl;
	}
	*/
	int day = 0;
	int cur = tot;
	while(cur >= 1){
		int mi = 1e9;
		int cnt = 0;
		while(cur >= 1 && cnt < k){
			cnt++;
			mi = min(mi, a[cur]);
			cur--;
		}
		if(mi < day)
			return 0;
		day++;
	}
	return 1;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1 ; i <= n; i++){
		scanf("%d", &f[i]);
	}
	sort(f + 1, f + n + 1, cmp);
	for(int i = 1; i <= m; i++){
		scanf("%d", &g[i].s);
		g[i].id = i;
	}
	sort(g + 1, g + m + 1);
	//cout << check(0) << endl;
	
	int L = 0, R = m;
	while(L < R){
		int M = (L + R + 1) >> 1;
		if(check(M))
			L = M;
		else
			R = M - 1;
	}
	if(!check(L)){
		puts("-1");
	}
	else{
		printf("%d\n", L);
		for(int i = 1; i <= L; i++){
			printf("%d ", g[i].id);
		}
		if(L == 0)
			puts("");
	}
	
	return 0;
}