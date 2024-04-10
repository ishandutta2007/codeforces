#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 111111;
const int INF = 100005; 

set<pair<int, int> > values;
set<pair<int, int> > fval;
int n, s, l;
int a[N], f[N];

int main() {
	scanf("%d %d %d", &n, &s, &l);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	f[1] = 0;
	for(int i = 1, j = 1; i <= n; i++) {
		values.insert(make_pair(a[i], i));
		if (j <= i - l + 1) {
			fval.insert(make_pair(f[i - l + 1], i - l + 1));
		}
		while(values.rbegin()->first - values.begin()->first > s) {
			values.erase(make_pair(a[j], j));
			fval.erase(make_pair(f[j], j));
			j++;
		}
		f[i + 1] = INF;
		if (j <= i - l + 1 && !fval.empty()) {
			f[i + 1] = fval.begin()->first + 1;
		}
	}
	printf("%d\n", f[n + 1] >= INF ? -1 : f[n + 1]);
	return 0;
}