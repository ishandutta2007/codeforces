#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 400005
using namespace std;
typedef long long ll;
int n,m,q;
int par[maxn],hei[maxn];
void ini(int x){
	for(int i=1;i<=x;i++){
		par[i] = i;
		hei[i] = 1;
	}
}
int fin(int x){
	if(par[x] == x) return x;
	return par[x] = fin(par[x]);
}
void uni(int x,int y){
	x = fin(x);
	y = fin(y);
	if(x == y) return;
	if(hei[x] < hei[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(hei[x] == hei[y]) hei[x]++;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	ini(n + m);
	for(int i=1;i<=q;i++){
		int r,c;
		scanf("%d%d",&r,&c);
		uni(r,c + n);
	}
	int ans = 0;
	for(int i=1;i<=n+m;i++){
		if(par[i] == i) ans++;
	}
	printf("%d\n",ans - 1);
	return 0;
}