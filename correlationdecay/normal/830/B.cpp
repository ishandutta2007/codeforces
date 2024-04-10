#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <iostream>
#define maxn 100009
using namespace std;
int n, m, p, tot;
int a[maxn], X[maxn];
int f[maxn];
vector<int>G[maxn];

int bin(int id, int x){
	int L = 0, R = G[id].size();
	while(L < R){
		int M = (L + R) >> 1;
		if(G[id][M] > x)
			R = M;
		else
		 	L = M + 1;
	}
	return R;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		X[tot++] = a[i];
	}
	
	sort(X, X + tot);
	tot = unique(X, X + tot) - X;
	
	for(int i = 0; i < tot; i++)
		f[X[i]] = i;
	
	for(int i = 1; i <= n; i++){
		a[i] = f[a[i]];
	}
	
	for(int i = 1; i <= n; i++){
		G[a[i]].push_back(i);
	}
	
	long long ans = 0, cur = 1;
	ans += G[0].size();
	
	int sz = G[0].size();
	int last = G[0][sz - 1];
	
	for(int i = 1; i < tot; i++){
		int sz = G[i].size();
		if(last < G[i][0]){
			ans += 1LL * cur * sz;
			last = G[i][sz - 1];
		}
		else if(last > G[i][sz - 1]){
			cur++;
			ans += 1LL * cur * sz;
			last = G[i][sz - 1];
		}
		else{
			int pos = bin(i, last);
			ans += 1LL * cur * (sz - 1 - pos + 1);
			cur++;
			ans += 1LL * cur * pos;
			last = G[i][pos - 1];
		}
	}
	
	cout << ans << endl;
	return 0;
}