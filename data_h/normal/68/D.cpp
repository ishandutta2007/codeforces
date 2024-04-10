#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

map<int, int> sum, cost;

int h, q;
char str[10];
int pos, e;
double ans, mi[1000];
int turn[1000];

double func(int depth, int x, double Max) {
	if (depth == h) {
		if (cost.count(x)) {
			return cost[x];
		}
		return max(Max, (double)cost[x]);
	}
	int L = sum[x << 1], R = sum[x << 1 | 1], cur = cost[x];
	if (L + R + cur == 0)
		return 0;
	double Lans = max(Max, (double)cur + R), Rans = max(Max, (double)cur + L);
	if (L > cur + R && L > Lans) 
		Lans = func(depth + 1, x << 1, Lans);
	if (R > cur + L && R > Rans)
		Rans = func(depth + 1, x << 1 | 1, Rans);
	return (Lans + Rans) / 2.0;
}

int main() {
	scanf("%d %d", &h, &q);
	ans = 0;
	mi[0] = 1;
	for(int i = 1; i <= 40; i++)
		mi[i] = mi[i - 1] * 2;
	for(int i = 1; i <= q; i++) {
		scanf("%s", str);
		if (str[0] == 'a') {
			scanf("%d %d", &pos, &e);
			cost[pos] += e;
			while(pos) {
				sum[pos] += e;
				pos /= 2;
			}
		} else {
			printf("%.12lf\n", func(0, 1, 0));
		}
	}
	return 0;
}