#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=2e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int bit[N], a[N], b[N], c[N], n, st[N], tot;

void add(int x, int d){
	for(;x <= n;x += x & -x) bit[x] += d;
}
int ask(int x){
	int ret = 0;
	for(;x;x -= x & -x) ret += bit[x];
	return ret;
}
int cmp(int x, int y){
	return a[x] < a[y];
}
int main(){
//	freopen("111.in","r",stdin); 
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]), b[i] = i;
	sort(b + 1, b + n + 1, cmp);
	for(int i = 1;i <= n;i ++){
		int k = b[i];
		for(int j = 1;(k - 1) * j + 2 <= n && j < n;j ++) c[j] += ask(min(k * j + 1, n)) - ask((k - 1) * j + 1);
		st[++ tot] = k;
		if(i == n || (i < n && a[k] != a[b[i + 1]])) while(tot) add(st[tot --], 1);
	}
	for(int i = 1;i < n;i ++) printf("%d%c", c[i], (i < n - 1) ? ' ' : '\n');
	return 0;
}