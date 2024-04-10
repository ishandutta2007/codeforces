#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int c[11][10][4][100100];
char s[100100], t[20];
int q, n;

inline int get(char c){
	return c == 'A' ? 0 : c == 'T' ? 1 : c == 'G' ? 2 : 3;
}

void add(int i, int j, int k, int x){
	for(; x <= n; x += x & -x) ++c[i][j][k][x];
}

void del(int i, int j, int k, int x){
	for(; x <= n; x += x & -x) --c[i][j][k][x];
}

int ask(int i, int j, int k, int x){
	int res = 0;
	for(; x; x -= x & -x) res += c[i][j][k][x];
	return res;
}

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i){
		for(int k = 1; k <= 10; ++k){
			add(k, i % k, get(s[i]), i);
		}
	}
	
	scanf("%d", &q);
	while(q--){
		static int op, x, l, r;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d%s", &x, t);
			if(s[x] == t[0]) continue;
			for(int k = 1; k <= 10; ++k){
				del(k, x % k, get(s[x]), x);
				add(k, x % k, get(t[0]), x);
			}
			s[x] = t[0];
		}else{
			scanf("%d%d%s", &l, &r, t);
			int m = strlen(t);
			int res = 0;
			for(int i = 0; i < m; ++i){
				int lt = l + i;
				if(l + i > r) continue;
				res += ask(m, lt % m, get(t[i]), r) - ask(m, lt % m, get(t[i]), l - 1);
			}
			printf("%d\n", res);
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}