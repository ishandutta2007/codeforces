#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#define maxn 100009
using namespace std;
char s[maxn], t[100];
int b[4][11][11][maxn];
int n = 0;

int getid(char c){
	int id = 0;
	if(c == 'A') id = 0;
	if(c == 'T') id = 1;
	if(c == 'G') id = 2;
	if(c == 'C') id = 3;
	return id;
}

void update(int id, int mod, int u, int x, int val){
	while(x < maxn){
		b[id][mod][u][x] += val;
		x += x & -x;
	}
}

void doit(int mod){
	for(int i = 1; i <= n; i++){
		int id = getid(s[i]);
		int u = i % mod;
		update(id, mod, u, i, 1);
	}
}

int getsum(int id, int mod, int u, int x){
	int sum = 0;
	while(x > 0){
		sum += b[id][mod][u][x];
		x -= x & -x;
	}
	return sum;
}

int query(int l, int r, int mod, int u, int id){
	return getsum(id, mod, u, r) - getsum(id, mod, u, l - 1);
}

void Case1(){
	int x;
	scanf("%d%s", &x, t);
	int newid = getid(t[0]);
	int oldid = getid(s[x]);
	s[x] = t[0];
	for(int mod = 1; mod <= 10; mod++){
		int u  = x % mod;
		update(oldid, mod, u, x, -1);
		update(newid, mod, u, x, 1);
	}
}

void Case2(){
	int l, r;
	scanf("%d%d%s", &l, &r, t);
	int mod = strlen(t);
	int ans = 0;
	for(int i = 0; i < mod; i++){
		ans += query(l, r, mod, (l + i) % mod, getid(t[i]));
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= 10; i++){
		doit(i);
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int tp;
		scanf("%d", &tp);
		if(tp == 1) Case1();
		else Case2();
	}
	return 0;
}