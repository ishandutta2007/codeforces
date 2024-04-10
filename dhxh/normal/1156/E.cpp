#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
int visl[maxn];
int visr[maxn];

long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int l, int r){
	int x, y;
	int mid = (l + r) / 2;
	int maxx = 0;
	
	if(l == r)return 0;
	
	dfs(l, mid);
	dfs(mid + 1, r);
	
	x = mid, y = mid + 1;
	maxx = max(a[x], a[y]);
	visl[a[x]] = 1;
	visr[a[y]] = 1;
	
	while(true){
		while(x - 1 >= l and a[x - 1] <= maxx){
			x--;
			visl[a[x]]++;
			ans += visr[maxx - a[x]];
		}
		while(y + 1 <= r and a[y + 1] <= maxx){
			y++;
			visr[a[y]]++;
			ans += visl[maxx - a[y]];
		}
		if(l == x and y == r)break;
		if(x - 1 < l){
			y++;
			visr[a[y]]++;
			maxx = max(maxx, a[y]);
		}else if(y + 1 > r){
			x--;
			visl[a[x]]++;
			maxx = max(maxx, a[x]);
		}else if(a[x - 1] > a[y + 1]){
			y++;
			visr[a[y]]++;
			maxx = max(maxx, a[y]);
		}else if(a[x - 1] < a[y + 1]){
			x--;
			visl[a[x]]++;
			maxx = max(maxx, a[x]);
		}else{
			y++;
			visr[a[y]]++;
			maxx = max(maxx, a[y]);
			x--;
			visl[a[x]]++;
			maxx = max(maxx, a[x]);
		}
	}
	
	for(int i=l;i<=r;i++){
		visl[a[i]] = 0;
		visr[a[i]] = 0;
	}
	
	return 0;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	dfs(1, n);
	
	printf("%lld\n", ans);
	
	return 0;
}