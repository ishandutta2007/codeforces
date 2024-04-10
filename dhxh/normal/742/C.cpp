#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int crash[105];
int cnt[105];
int fa[105];
int son[105];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int init(){
	int i, j;
	
	for(i=1;i<=n;i++){
		fa[i] = i;
		son[i] = 1;
	}
	
	return 0;
}

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	
	if(ra != rb){
		fa[rb] = ra;
		son[ra] += son[rb];
	}
	
	return 0;
}

int gcd(int a, int b){
	if(a % b){
		return gcd(b, a % b);
	}else{
		return b;
	}
}

int main(){
	int i, j;
	long long ans = 1;
	
	n = read();
	
	for(i=1;i<=n;i++){
		crash[i] = read();
		cnt[crash[i]]++;
	}
	
	for(i=1;i<=n;i++){
		if(cnt[i] == 0){
			cout << -1 << endl;
			return 0;
		}
	}
	
	init();
	
	for(i=1;i<=n;i++){
		join(i, crash[i]);
	}
	
	for(i=1;i<=n;i++){
		if(find(i) == i){
			if(son[i] % 2){
				ans = ans / gcd(ans, son[i]) * son[i];
			}else{
				ans = ans / gcd(ans, son[i] / 2) * son[i] / 2;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}