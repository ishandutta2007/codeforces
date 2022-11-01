#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

int c[maxn];
int a[maxn];
int cnt[maxn];

bool v[maxn];

int ans = 0;

queue <int> q;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x){
	if(v[x]){
		return c[x];
	}
	
	v[x] = true;
	
	return min(c[x], dfs(a[x]));
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		c[i] = read();
	}
	
	for(i=1;i<=n;i++){
		a[i] = read();
		cnt[a[i]]++;
	}
	
	for(i=1;i<=n;i++){
		if(cnt[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		v[x] = true;
		cnt[a[x]]--;
		
		if(cnt[a[x]] == 0){
			q.push(a[x]);
		}
	}
	
	for(i=1;i<=n;i++){
		if(!v[i]){
			ans += dfs(i);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}