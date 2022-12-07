#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long

int n, x, y, s;

const int maxn = 10000;
struct node{
	int dis, t;
}p[maxn];
bool cmp (const node &a, const node &b) { return a.dis < b.dis; }

int main(){
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	scanf("%d %d", &n, &s);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &x, &y, &p[i].t);
		p[i].dis = x * x + y * y;
	}
	sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		s += p[i].t;
		if (s >= 1000000) { printf("%lf\n", sqrt(1.0*p[i].dis)); return 0; } 
	}
	printf("-1\n");
	return 0;
}