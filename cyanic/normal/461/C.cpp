#include<bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l+r) >> 1)
using namespace std;
//()
//
//O(p*logn)
//p=n
//O(n*logn)

inline int read(){
	char ch = getchar(); int x = 0;
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }
	return x;
}

void write(int x){
	if (x >= 10) write(x/10); putchar(x%10+'0');
}

const int maxn = 200009;
int T[maxn<<2], n, Q, op, L, R;
int a, b, rev = 0;

void build(int o, int l, int r){
	if (l == r){
		if (r <= n) T[o] = 1; return;
	}
	build(lc, l, mid); build(rc, mid+1, r);
	T[o] = T[lc] + T[rc];
}

void update(int o, int l, int r, int x, int y){
	if (l == r) { T[o] += y; return; }
	if (x <= mid) update(lc, l, mid, x, y);
	else update(rc, mid+1, r, x, y);
	T[o] = T[lc] + T[rc];
}

int query(int o, int l, int r, int x, int y){
	if (l == x && y == r) return T[o];
	int res = 0;
	if (x <= mid) res += query(lc, l, mid, x, min(y, mid));
	if (mid+1 <= y) res += query(rc, mid+1, r, max(mid+1, x), y);
	return res;
}

int query(int x){
	return query(1, 1, 2*n, x, x);
}

int main(){
	n = read(); Q = read();
	build(1, 1, 2*n); L = 1; R = n;
	while (Q--){
		op = read();
		if (!rev){
			if (op == 1){
				a = read()+L-1;
				if (a-L+1 <= R-a){
					for (int i=L; i<=a; i++){
						update(1, 1, 2*n, 2*a+1-i, query(i));
						update(1, 1, 2*n, i, -query(i));
					}
					L = a+1;
				}
				else{
					for (int i=R; i>=a+1; i--){
						update(1, 1, 2*n, 2*a+1-i, query(i));
						update(1, 1, 2*n, i, -query(i));
					}
					R = a;
					rev ^= 1;
				}
			}
			else{
				a = read()+L; b = read()+L-1;
				write(query(1, 1, 2*n, a, b)); puts("");
			}
		}
		else{
			if (op == 1){
				a = R-read();
				if (a-L+1 <= R-a){
					for (int i=L; i<=a; i++){
						update(1, 1, 2*n, 2*a+1-i, query(i));
						update(1, 1, 2*n, i, -query(i));
					}
					L = a+1;
					rev ^= 1;
				}
				else{
					for (int i=R; i>=a+1; i--){
						update(1, 1, 2*n, 2*a+1-i, query(i));
						update(1, 1, 2*n, i, -query(i));
					}
					R = a;
				}
			}
			else{
				b = R-read(); a = R-read()+1; 
				write(query(1, 1, 2*n, a, b)); puts("");
			}
		}
	}
	return 0;
}