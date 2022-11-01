#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int a[maxn];
int b[maxn];

int f[2 * maxn];
int op[2 * maxn];
bool v[2 * maxn];
int mod;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, int t){
	v[x] = true;
	f[x] = t;
	
	if(!v[op[x]]){
		dfs(op[x], !t);
	}
	
	if(!v[x ^ 1]){
		dfs(x ^ 1, !t);
	}
	
	return 0;
}

int main(){
	int i, j;
	
	n = read();
	
	mod = 2 * n;
	
	for(i=1;i<=n;i++){
		a[i] = read();
		b[i] = read();
		a[i]--;
		b[i]--;
		op[a[i]] = b[i];
		op[b[i]] = a[i];
	}
	
	for(i=0;i<2*n;i++){
		if(!v[i]){
			dfs(i, 0);
		}
	}
	
	for(i=1;i<=n;i++){
		cout << f[a[i]] + 1 << " " << f[b[i]] + 1 << endl;
	}
	
	return 0;
}