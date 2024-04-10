#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#define maxn 500009
using namespace std;
int n, m;
struct node{
	int a,b;
	long long h;
	node(int _a = 0, int _b = 0, long long _h = 0){
		a = _a;
		b = _b;
		h = _h;
	}
	bool operator < (const node &rhs)const{
		return b > rhs.b;
	}
}a[maxn],b[maxn];
long long c[maxn], dp[maxn];
int X[maxn], tot;
map<int,int>mp;
long long getmax(int x){
	long long ans = 0;
	while(x > 0){
		ans = max(ans, c[x]);
		x -= x & -x;
	}
	return ans;
}
void update(int x, long long v){
	while(x < maxn){
		c[x] = max(c[x], v);
		x += x & -x;
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x, b, h;
		scanf("%d%d%d", &x, &b, &h);
		a[i] = node(x, b, h);
	}
	sort(a + 1, a + 1 + n);
	b[1] = a[1];
	m = 1;
	for(int i = 2; i <= n; i++){
		if(a[i].b == a[i - 1].b){
			b[m].a = min(b[m].a, a[i].a);
			b[m].h += a[i].h;
		}
		else{
			b[++m] = a[i];
		}
	}
	for(int i = 1; i <= m; i++){
		X[tot++] = b[i].a;
		X[tot++] = b[i].b;
	}
	sort(X, X + tot);
	tot = unique(X, X + tot) - X;
	for(int i = 0 ; i < tot; i++){
		mp[X[i]] = i + 1;
	}
	for(int i = 1; i <= m; i++){
		b[i].a = mp[b[i].a];
		b[i].b = mp[b[i].b];
	}
	long long ans = 0;
	for(int i = 1; i <= m; i++){
		dp[i] = getmax(b[i].b - 1) + b[i].h;
		ans = max(ans, dp[i]);
		update(b[i].a, dp[i]);
	}
	cout << ans << endl;
	return 0;
}