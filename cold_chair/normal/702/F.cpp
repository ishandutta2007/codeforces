#include<bits/stdc++.h>

#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)

#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)

#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)

#define ll long long

#define pp printf

#define hh pp("\n")

using namespace std;



const int N = 2e5 + 5;



int n;



struct P {

	int x, y;

} a[N];


int cmp(P a, P b) {
	return a.y == b.y ? a.x < b.x : a.y > b.y;
}


ll s[N];



int k;

#define x0 t[x][0]
#define x1 t[x][1]

int t[N][2], c[2];
int b[N], lz1[N];
int ans[N], lz2[N];
int siz[N];

void jia1(int x, int v) {
	if(x) b[x] += v, lz1[x] += v;
}
void jia2(int x, int v) {
	if(x) ans[x] += v, lz2[x] += v;
}
void down(int x) {
	if(lz1[x]) jia1(x0, lz1[x]), jia1(x1, lz1[x]), lz1[x] = 0;
	if(lz2[x]) jia2(x0, lz2[x]), jia2(x1, lz2[x]), lz2[x] = 0; 
}
void upd(int x) {
	if(x) siz[x] = siz[x0] + siz[x1] + 1;
}
void split(int x, int k) {	
	c[0] = c[1] = 0; if(!x) return;
	down(x);
	int z = siz[x0] < k;
	split(t[x][z], k - z * (siz[x0] + 1));
	t[x][z] = c[!z]; c[!z] = x;
	upd(x);
}
int mer(int x, int y) {
	if(!x || !y) return x + y;
	down(x); down(y);
	if(rand() % (siz[x] + siz[y]) < siz[x]) {
		t[x][1] = mer(t[x][1], y);
		upd(x); return x;
	} else {
		t[y][0] = mer(x, t[y][0]);
		upd(y); return y;
	}
}


int cmpd(int x, int y) { return b[x] < b[y];}

int rt;

int ef(int x, int k) {
	if(!x) return 0;
	down(x);
	if(b[x] <= k) return siz[x0] + 1 + ef(x1, k);
	return ef(x0, k);
}

int d[N], d0;

void dg(int x) {
	if(!x) return;
	d[++ d0] = x;
	down(x);
	dg(x0); dg(x1);
}

void ins(int &rt, int x) {
	int k = ef(rt, b[x]);
	split(rt, k);
	rt = mer(mer(c[0], x), c[1]);
}

//void dfs(int x) {
//	if(!x) return;
//	pp("%d %d %d\n", x, x0, x1);
//	dfs(x0); dfs(x1);
//}

void work(int x) {
	int k1 = ef(rt, x - 1);
	split(rt, k1);
	
	int c0 = c[0];
	int k2 = ef(c[1], 2 * x - 1);
	
	split(c[1], k2);
	
	int c1 = c[0], c2 = c[1];
	
	jia1(c2, -x);
	jia2(c2, 1);
	
	jia1(c1, -x);
	jia2(c1, 1);
	
	d0 = 0;
	dg(c1);
	
	fo(i, 1, d0) {
	
		t[d[i]][0] = t[d[i]][1] = 0;
		siz[d[i]] = 1;
		
		ins(c0, d[i]);
	}
	
	rt = mer(c0, c2);
	
}


int main() {


	scanf("%d", &n);

	fo(i, 1, n) scanf("%d %d", &a[i].x, &a[i].y);

	sort(a + 1, a + n + 1, cmp);

	scanf("%d", &k);
	static int d[N];
	fo(i, 1, k) {
		scanf("%d", &b[i]);
		d[i] = i;
		siz[i] = 1;
	}
	sort(d + 1, d + k + 1, cmpd);
	fo(i, 1, k) {
		rt = mer(rt, d[i]);
	}
	fo(i, 1, n) {
		work(a[i].x);
	}
	dg(rt);
	fo(i, 1, k) pp("%d ", ans[i]);

}