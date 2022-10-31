#include <cstdio> 
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

const int MAXQ = 610005, MAXN = 510;
struct Quer {
	int x1, y1, x2, y2, id;
	void read(int num) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		id = num;
	}
}q[MAXQ], qq[MAXQ];
bitset<MAXN> dp[MAXN][MAXN], now;
char map[MAXN][MAXN];
int n, m, qnum, ans[MAXQ];

void Work(int l, int r, int ql, int qr) {
	int mid = (l + r) / 2;
	for(int i = 0; i <= n + 1; i++)
		for(int j = l; j <= r; j++)
			dp[i][j].reset();
	for(int i = 1; i <= n; i++) {
		if (map[i][mid] == '.') {
			dp[i][mid][i] = 1;
			dp[i][mid] |= dp[i - 1][mid];
		}			
	}
	for(int i = mid + 1; i <= r; i++) {
		for(int j = 1; j <= n; j++) {
			if (map[j][i] != '#') {
				dp[j][i] = dp[j - 1][i] | dp[j][i - 1];
			}
		}
	}
	for(int i = n; i >= 1; i--) {
		dp[i][mid].reset();
		if (map[i][mid] == '.') {
			dp[i][mid][i] = 1;
			dp[i][mid] |= dp[i + 1][mid];
		}
	}
	for(int i = mid - 1; i >= l; i--) {
		for(int j = n; j >= 1; j--) {
			if (map[j][i] != '#') {
				dp[j][i] = dp[j + 1][i] | dp[j][i + 1];
			}
		}
			
	}
	int val;
	for(int i = ql; i <= qr; i++) {
		if (q[i].y1 <= mid && q[i].y2 >= mid) {
			if (q[i].y2 == mid)
				val = dp[q[i].x1][q[i].y1][q[i].x2];
			else
			if (q[i].y1 == mid)
				val = dp[q[i].x2][q[i].y2][q[i].x1];
			else 
				val = ((dp[q[i].x1][q[i].y1] & dp[q[i].x2][q[i].y2]).count() > 0);
			ans[q[i].id] = val;
		}
	}
	int split, top = ql - 1;	
	for(int i = ql; i <= qr; i++) {
		if (q[i].y2 < mid) 
			qq[++top] = q[i];
	}
	split = top;
	for(int i = ql; i <= qr; i++) {
		if (q[i].y1 > mid) 
			qq[++top] = q[i];
	}
	for(int i = ql; i <= top; i++)
		q[i] = qq[i];
	if (split >= ql && l < mid)
		Work(l, mid - 1, ql, split);
	if (split < top && mid < r)
		Work(mid + 1, r, split + 1, top);
}


int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", map[i] + 1);
	}
	scanf("%d", &qnum);
//	if (n == 100 && m == 100) {
//		printf("%d", qnum);
//	}
	for(int i = 1; i <= qnum; ++i) {
		q[i].read(i);
	}
	Work(1, m, 1, qnum);
	//sort(q + 1, q + qnum + 1, cmp);
	for(int i = 1; i <= qnum; i++) {
		printf("%s\n", ans[i] == 1 ? "Yes" : "No");
	}
	return 0;
}