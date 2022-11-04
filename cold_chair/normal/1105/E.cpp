#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<ctime>
#define pp printf
#define ll long long
#define gc getchar
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int n, m, op;
string s;
char ss[45];

map<string, int> p;

int bz[45], a[45][45], d[45];
int b[45], bx[45];

int main() {
//	freopen("a.in", "r", stdin);
	srand(time (0));
	scanf("%d %d", &n, &m);
	m = 0;
	fo(i, 1, n) {
		scanf("%d", &op);
		if(op == 1) {
			fo(j, 1, m) bz[j] = 0;
			d[0] = 0;
		} else {
			scanf("%s", ss);
			s = string(ss);
			int h;
			if(!p.count(s)) p[s] = h = ++ m; else h = p[s];
			if(!bz[h]) {
				bz[h] = 1;
				fo(j, 1, d[0]) a[d[j]][h] = a[h][d[j]] = 1;
				d[++ d[0]] = h;
			}
		}
	}
//	fo(i, 1, m) {
//		fo(j, 1, m) pp("%d", a[i][j]);
//		pp("\n");
//	}
	fo(i, 1, m) b[i] = i;
	int ans = 0;
	const auto len = 1.7 * CLOCKS_PER_SEC;
	auto st = clock(), ed = st;
//	fo(ii, 1, 1e4) {
	while( ed-st < len ){
		fo(ti,1,20){
			random_shuffle(b + 1, b + m + 1);
			int s = 0;
			fo(i, 1, m) bx[i] = 0;
			fo(i, 1, m) {
				int ky = 1;
				fo(j, 1, i - 1) if(bx[j] && a[b[j]][b[i]]) {
					ky = 0;
					break;
				}
				if(ky) {
					bx[i] = 1;
					s ++;	
				}
			}
			ans = max(ans, s);
		}
		ed = clock();
	}
	pp("%d", ans);
}