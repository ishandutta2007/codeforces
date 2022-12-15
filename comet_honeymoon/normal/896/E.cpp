#include<bits/stdc++.h>
using namespace std;

class Fastinput{
	char buf[1 << 21], *p1 = buf, *p2 = buf, c;
	public:
		char inline mygetc() {
			return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *(p1++);
		}
		template<typename T> void read(T &x) {
			bool neg = 0; c = mygetc();
			for(x = 0; !isdigit(c); c = mygetc()) if(c == '-') neg = 1;
			while(isdigit(c)) x = x * 10 + (c & 15), c=mygetc();
			if(neg) x = -x;
		}
}Fin;

const int maxN = 1000005, len = 1500;

struct Qs{
	int QL, QR, QX; bool Qtyp;
}B[maxN >> 1];
int ANS[maxN >> 1];

int N, M; int beg[maxN / len + 100], inb[maxN];
int lzy, mx;

int fa[len + 5], siz[len + 5], val[len + 5], lav[maxN];
int A[maxN]; 
int find(int x) {return (fa[x] == x) ? x : fa[x] = find(fa[x]);}
void inline merge(int x, int y) {
	int u = lav[x], v = lav[y]; lav[x] = lav[y] = val[u] = val[v] = 0;
	if(siz[u] > siz[v]) swap(u, v);
	if(!v) return;
	if(u) siz[v] += siz[u], siz[u] = 0, fa[u] = v;
	val[lav[y] = v] = y;
}

void inline init(int L, int R) {
	for(int j = 1; j <= R - L; j++) {
		int p = A[j + L - 1]; mx = max(mx, p);
		if(!lav[p]) lav[p] = j, fa[j] = j, siz[j] = 1, val[j] = p;
		else fa[j] = lav[p], siz[lav[p]]++;
	}
}

int main(){
	Fin.read(N), Fin.read(M);
	for(int i = 1; i <= N; i++)
		Fin.read(A[i]), inb[i] = (i - len >= 1) ? inb[i - len] + 1 : 1, 
		beg[inb[i]] = beg[inb[i]] ? beg[inb[i]] : i;
	beg[inb[N + 1] = inb[N] + 1] = N + 1;
	for(int i = 1; i <= M; i++){
		int tmp; Fin.read(tmp); B[i].Qtyp = tmp - 1;
		Fin.read(B[i].QL), Fin.read(B[i].QR), Fin.read(B[i].QX);
	}
	
	for(int d = 1; d <= inb[N]; d++) {
		lzy = mx = 0;
		memset(lav, 0, sizeof(lav)); memset(siz, 0, sizeof(siz));
		memset(fa, 0, sizeof(fa)); memset(val, 0, sizeof(val));
		init(beg[d], beg[d + 1]);
		for(int i = 1; i <= M; i++) {
			int x = B[i].QX, L = B[i].QL, R = B[i].QR, iL = inb[L], iR = inb[R];
			if(B[i].Qtyp) {
				if(x + lzy > 1000000) continue;
				if(iL + 1 <= d && d <= iR - 1)
					ANS[i] += siz[lav[x + lzy]];
				else if(iL == d || iR == d) {
					for(int j = max(L, beg[d]); j < beg[d + 1] && j <= R; j++) 
						if(val[find(j - beg[d] + 1)] - lzy == x) ANS[i]++;
				}
			}
			else{
				if(x >= mx) continue;
				if(iL + 1 <= d && d <= iR - 1)
					if(2 * x > mx) {
						for(int j = lzy + x + 1; j <= lzy + mx; j++) merge(j, j - x);
						mx = min(x, mx);
					}
					else {
						for(int j = lzy + 1; j <= lzy + x; j++) merge(j, j + x);
						lzy += x; mx -= x;
					}
				else if(iL == d || iR == d) {
					for(int j = 1; j <= beg[d + 1] - beg[d]; j++)
						lav[A[j + beg[d] - 1] = val[find(j)]] = 0, A[j + beg[d] - 1] -= lzy;
					for(int j = 1; j <= beg[d + 1] - beg[d]; j++)
						siz[j] = fa[j] = val[j] = 0;
					for(int j = max(L, beg[d]); j < beg[d + 1] && j <= R; j++)
						if(A[j] > x) A[j] -= x;
					lzy = mx = 0;
					init(beg[d], beg[d + 1]);
				}
			}
		}
	}
	for(int i = 1; i <= M; i++) if(B[i].Qtyp == 1) printf("%d\n", ANS[i]);
}