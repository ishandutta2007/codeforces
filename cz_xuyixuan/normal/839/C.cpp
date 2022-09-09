#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
vector <int> a[MAXN];
double get(int pos, int fa) {
	int cnt = a[pos].size();
	if (fa != 0) cnt--;
	if (cnt == 0) return 0;
	double tans = 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) tans += 1 + get(a[pos][i], pos);
	return tans / cnt;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	printf("%.12lf\n", get(1, 0));
	return 0;
}