//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

struct NODE {
	int x,y;
	bool operator < (const NODE &b) const {return (x != b.x) ? (x < b.x) : (y < b.y);}
} a[MAXN];

int T,n;
int maxy,id;
bool flag;

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(register int i = 1;i <= n; ++i)
			scanf("%d%d",&a[i].x,&a[i].y);
		maxy = -1;
		flag = true;
		sort(a + 1,a + n + 1);
		for(register int i = 1;i <= n; ++i) 
			for(register int j = 1;j <= n; ++j)
				if(a[i].x > a[j].x && a[i].y < a[j].y) {flag = false; break;}
		if(!flag) {puts("NO"); continue;}
		puts("YES");
		for(register int i = 1;i <= n; ++i) {
			for(register int p = 1;p <= a[i].x - a[i - 1].x; ++p) printf("R");
			for(register int p = 1;p <= a[i].y - a[i - 1].y; ++p) printf("U");
		}
		puts("");
	}
	return 0;
}