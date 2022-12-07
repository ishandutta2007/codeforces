#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define all(a) a.begin(), a.end()

#define DirR 0
#define DirL 1
#define DirD 2
#define DirU 3
const int xx[] = {0, 0, 1, -1};//R:0 L:1 D:2 U:3
const int yy[] = {1, -1, 0, 0};
int w[100000][6];
int g[100000];
int m;
int a[7], b[7];
int N, M;
int even;

#define w(x,y,z) w[(y - 1) * a[1] + x - 1][z - 1]
#define g(x,y) g[(y - 1) * a[1] + x - 1]
void init(){
	for(int i = m + 1; i <= 6; ++i) a[i] = b[i] = 1;
	
	for(int i = 1; i <= a[6]; ++i)
		for(int j = 1; j <= a[5]; ++j)
			for(int k = 1; k <= a[4]; ++k)
				for(int p = 1; p <= a[3]; ++p)
					for(int q = 1; q <= a[2]; ++q){
						int y = (i - 1) * a[5] * a[4] * a[3] * a[2] + (j - 1) * a[4] * a[3] * a[2] + (k - 1) * a[3] * a[2] + (p - 1) * a[2] + q;
						for(int x = 1; x <= a[1]; ++x){
							w(x,y,1) = x;
							w(x,y,2) = ((i - 1) * a[5] * a[4] * a[3] + (j - 1) * a[4] * a[3] + (k - 1) * a[3] + p) & 1 ? q : a[2] - q + 1;
							w(x,y,3) = ((i - 1) * a[5] * a[4] + (j - 1) * a[4] + k) & 1 ? p : a[3] - p + 1;
							w(x,y,4) = ((i - 1) * a[5] + j) & 1 ? k : a[4] - k + 1;
							w(x,y,5) = i & 1 ? j : a[5] - j + 1;
							w(x,y,6) = i;
						}
					}
	N = a[1], M = a[2] * a[3] * a[4] * a[5] * a[6];
	/*
	for(int i = 1; i <= N; puts(""), ++i)
		for(int j = 1; j <= M; ++j){
			printf("{");
			for(int k = 1; k <= 6; ++k){
				printf("%d", w(i,j,k));
				if(k < 6) printf(",");
			}
			printf("}   ");
		}
	*/
	//check
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j){
			if(i < N){
				int tmp = 0;
				for(int k = 1; k <= 6; ++k)
					tmp += abs(w(i,j,k) - w(i+1,j,k));
				assert(tmp == 1);
			}
			if(j < M){
				int tmp = 0;
				for(int k = 1; k <= 6; ++k)
					tmp += abs(w(i,j,k) - w(i,j+1,k));
				assert(tmp == 1);
			}
		}
}

inline void walk(int x, int y, int tx, int ty){
	//printf("(%d,%d)->(%d,%d)\n", x, y, tx, ty);
	for(int i = 1; i <= m; ++i)
		if(w(x,y,i) != w(tx,ty,i)){
			if(w(tx,ty,i) > w(x,y,i))
				printf("inc %d\n", i);
			else printf("dec %d\n", i);
			return;
		}
}

void work_LU_H(int lx, int rx, int ly, int ry){ //from Left Up horizontal
	for(int i = lx; i <= rx; i += 2){
		for(int j = ly; j < ry; ++j)
			g(i,j) = DirR;
		g(i,ry) = DirD;
	}
	for(int i = lx + 1; i <= rx; i += 2){
		for(int j = ly + 1; j <= ry; ++j)
			g(i,j) = DirL;
		g(i,ly) = DirD;
	}
}

void work_LU_V(int lx, int rx, int ly, int ry){ //from Left Up vertical
	for(int j = ly; j <= ry; j += 2){
		for(int i = lx; i < rx; ++i)
			g(i,j) = DirD;
		g(rx,j) = DirR;
	}
	for(int j = ly + 1; j <= ry; j += 2){
		for(int i = lx + 1; i <= rx; ++i)
			g(i,j) = DirU;
		g(lx,j) = DirR;
	}
}

void work_RU_H(int lx, int rx, int ly, int ry){ //from Right Up horizontal
	for(int i = lx; i <= rx; i += 2){
		for(int j = ly + 1; j <= ry; ++j)
			g(i,j) = DirL;
		g(i,ly) = DirD;
	}
	for(int i = lx + 1; i <= rx; i += 2){
		for(int j = ly; j < ry; ++j)
			g(i,j) = DirR;
		g(i,ry) = DirD;
	}
}

void work_RU_V(int lx, int rx, int ly, int ry){ //from Right Up vertical
	for(int j = ry; j >= ly; j -= 2){
		for(int i = lx; i < rx; ++i)
			g(i,j) = DirD;
		g(rx,j) = DirL;
	}
	for(int j = ry - 1; j >= ly; j -= 2){
		for(int i = lx + 1; i <= rx; ++i)
			g(i,j) = DirU;
		g(lx,j) = DirL;
	}
}

void work_LD_H(int lx, int rx, int ly, int ry){ //from Left Down horizontal
	for(int i = rx; i >= lx; i -= 2){
		for(int j = ly; j < ry; ++j)
			g(i,j) = DirR;
		g(i,ry) = DirU;
	}
	for(int i = rx - 1; i >= lx; i -= 2){
		for(int j = ly + 1; j <= ry; ++j)
			g(i,j) = DirL;
		g(i,ly) = DirU;
	}
}

void work_LD_V(int lx, int rx, int ly, int ry){ //from Left Down vertical
	for(int j = ly; j <= ry; j += 2){
		for(int i = lx + 1; i <= rx; ++i)
			g(i,j) = DirU;
		g(lx,j) = DirR;
	}
	for(int j = ly + 1; j <= ry; j += 2){
		for(int i = lx; i < rx; ++i)
			g(i,j) = DirD;
		g(rx,j) = DirR;
	}
}

void work_RD_H(int lx, int rx, int ly, int ry){ //from Right Down horizontal
	for(int i = rx; i >= lx; i -= 2){
		for(int j = ly + 1; j <= ry; ++j)
			g(i,j) = DirL;
		g(i,ly) = DirU;
	}
	for(int i = rx - 1; i >= lx; i -= 2){
		for(int j = ly; j < ry; ++j)
			g(i,j) = DirR;
		g(i,ry) = DirU;
	}
}

void work_RD_V(int lx, int rx, int ly, int ry){ //from Right Down vertical
	for(int j = ry; j >= ly; j -= 2){
		for(int i = lx + 1; i <= rx; ++i)
			g(i,j) = DirU;
		g(lx,j) = DirL;
	}
	for(int j = ry - 1; j >= ly; j -= 2){
		for(int i = lx; i < rx; ++i)
			g(i,j) = DirD;
		g(rx,j) = DirL;
	}
}

void work(){
	if(m == 1){
		if(b[1] != 1 && b[1] != a[1]) puts("No");
		else{
			if(a[1] == 2){
				puts("Cycle");
				if(b[1] == 1) puts("inc 1"), puts("dec 1");
				else puts("dec 1"), puts("inc 1");
			}else{
				puts("Path");
				for(int i = 1; i < a[1]; ++i){
					if(b[1] == 1) printf("inc 1\n");
					else printf("dec 1\n");
				}
			}
		}
		return;
	}
	
	init();

	int x = b[1], y = -1;
	for(int i = 1; i <= M && y == -1; ++i)
		if(b[2] == w(x,i,2) && b[3] == w(x,i,3) && b[4] == w(x,i,4) && b[5] == w(x,i,5) && b[6] == w(x,i,6))y = i;
	if(even){
		puts("Cycle");
		if(M & 1){
			g(1,1) = DirR;
			work_LU_H(1, N, 2, M);
			g(N,2) = DirL;
			for(int i = 2; i <= N; ++i)
				g(i,1) = DirU;
		}else{
			g(1,1) = DirD;
			work_LU_V(2, N, 1, M);
			g(2,M) = DirU;
			for(int i = 2; i <= M; ++i)
				g(1,i) = DirL;
		}
		for(int i = 1; i <= N * M; ++i){
			int tx = x + xx[g(x,y)], ty = y + yy[g(x,y)];
			walk(x, y, tx, ty);
			x = tx, y = ty;
		}
	}else{
		if((x ^ y) & 1) { puts("No"); return; }
		puts("Path");
		if(x == 1){
			work_RU_V(1, N - 1, 1, y);
			g(N - 1,1) = DirD;
			for(int j = 1; j <= y; ++j)
				g(N,j) = DirR;
			if(y < M) work_LD_V(1, N, y + 1, M);

		}else if(x == N){
			work_RD_V(2, N, 1, y);
			g(2,1) = DirU;
			for(int j = 1; j <= y; ++j)
				g(1,j) = DirR;
			if(y < M) work_LU_V(1, N, y + 1, M);

		}else if(y == 1){
			work_LD_H(1, x, 1, M - 1);
			g(1,M - 1) = DirR;
			for(int i = 1; i <= x; ++i)
				g(i,M) = DirD;
			if(x < N) work_RU_H(x + 1, N, 1, M);

		}else if(y == M){
			work_RD_H(1, x, 2, M);
			g(1,2) = DirL;
			for(int i = 1; i <= x; ++i)
				g(i,1) = DirD;
			if(x < N) work_LU_H(x + 1, N, 1, M);

		}else if(x & 1){
			for(int i = 2; i <= x; ++i) g(i,y) = DirU;
			g(1,y) = DirL;
			work_RU_H(1, x, 1, y - 1);
			work_LU_V(x + 1, N, 1, y);
			work_LD_H(1, N, y + 1, M);
		}else{ //y & 1
			work_RD_V(1, x, 1, y);
			g(x,1) = DirD;
			work_LU_H(x + 1, N, 1, y);
			g(N,y) = DirR;
			work_LD_H(1, N, y + 1, M);
		}
		for(int i = 1; i < N * M; ++i){
			int tx = x + xx[g(x,y)], ty = y + yy[g(x,y)];
			walk(x, y, tx, ty);
			x = tx, y = ty;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("g.out", "w", stdout);
#endif
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) scanf("%d", a + i);
	even = 0;
	for(int i = 1; i <= m; ++i) scanf("%d", b + i), even |= !(a[i] & 1);
	
	work();

	return 0;
}