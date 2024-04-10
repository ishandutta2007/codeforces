#include <bits/stdc++.h>
#define Mid (l + r >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 100009;
struct node {
	int cnt, id;
	vector<int> v;
} a[N];
int cmp(const node &a, const node &b) {
	return a.cnt < b.cnt;
}
int n, m, t[N], ans[N], tot;
void work() { 
	n = read(); m = read(); tot = 0;
	for(int i = 1; i <= n; i++) t[i] = 0;
	for(int i = 1; i <= m; i++) {
		a[i].cnt = read();
		a[i].id = i;
		a[i].v.clear();
		for(int j = 1; j <= a[i].cnt; j++)
			a[i].v.push_back(read());
	}
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= m; i++) {
		int ff = 0;
		for(auto j : a[i].v) {
			if(t[j] < (m + 1) / 2) {
				t[j]++;
				ff = 1;
				ans[a[i].id] = j;
				break;
			}
		}
		if(ff == 0) {
			printf("NO\n");
			return ;
		}
	}
	printf("YES\n");
	for(int i = 1; i <= m; i++) 
		printf("%d ", ans[i]);
	printf("\n");
}
signed main()
{
	int Case = read();
	while(Case--) work();
	return 0;
}
/*
m/2



*/