#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
#define maxn 1000009
using namespace std;
int n, m;
int U[maxn], V[maxn];
int p[maxn];
int cnt[maxn];
int du[maxn], loop;

int findset(int x){
	return x == p[x] ? x : p[x] = findset(p[x]);
}

void unionset(int x, int y){
	p[findset(x)] = findset(y);
}

bool check(){
	for(int i = 1; i <= m; i++){
		cnt[findset(U[i])]++;
	}
	
	int num = 0;
	
	for(int i = 1; i <= n; i++){
		if(cnt[i] != 0)
			num++;
	}
	
	if(num > 1)
		return 0;
	else
		return 1;
}

int main(){
	scanf("%d%d", &n ,&m);
	
	for(int i = 1; i <= n; i++)
		p[i] = i;
	
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &U[i], &V[i]);
		unionset(U[i], V[i]);
		if(U[i] == V[i]){
			loop++;
		}
		else{
			du[U[i]]++;
			du[V[i]]++;
		}
	}
	
	if(!check()){
		puts("0");
		return 0;
	}
	
	long long ans = 0;
	ans = 1LL * loop * (loop - 1) / 2;
	
	ans += 1LL * loop * (m - loop);
	
	for(int i = 1; i <= n; i++){
		ans += 1LL * du[i] * (du[i] - 1) / 2;
	}
	
	cout << ans << endl;
	
	return 0;
}