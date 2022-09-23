#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<long long, pair<int, int> > plii;
long long row[100005], col[100005];
long long ans = 0;
priority_queue<plii, vector<plii>, less<plii> > pq;
map<pair<int, int>, int> M;

int main() {
	long long n, m, r, k; scanf("%lld%lld%lld%lld", &n, &m, &r, &k);
	for(int i = 1; i <= n; i++) {
		long long lower = (i >= r ? i - r + 1 : 1);
		long long upper = (i + r - 1 > n ? n - r + 1 : i);
		row[i] = upper - lower + 1;
	}
	for(int i = 1; i <= m; i++) {
		long long lower = (i >= r ? i - r + 1 : 1);
		long long upper = (i + r - 1 > m ? m - r + 1 : i);
		col[i] = upper - lower + 1;
	}
	sort(row + 1, row + n + 1);
	sort(col + 1, col + m + 1);

	//for(int i = 1; i <= n; i++) printf("%lld ", row[i]); puts("");
	//for(int i = 1; i <= m; i++) printf("%lld ", col[i]); puts("");

	pq.push(make_pair(row[n] * col[m], make_pair(n, m)));
	for(int i = 0; i < k; i++) {
		int rptr = pq.top().second.first, cptr = pq.top().second.second;
		//printf("%lld\n", pq.top().first);
		ans += pq.top().first; pq.pop();
		if(rptr > 1 && !M[make_pair(rptr - 1, cptr)]) { pq.push(make_pair(row[rptr - 1] * col[cptr], make_pair(rptr - 1, cptr))); M[make_pair(rptr - 1, cptr)]++; }
		if(cptr > 1 && !M[make_pair(rptr, cptr - 1)]) { pq.push(make_pair(row[rptr] * col[cptr - 1], make_pair(rptr, cptr - 1))); M[make_pair(rptr, cptr - 1)]++; }
	}
	//printf("%lld\n", ans);
	printf("%.15f", (double)ans / ((n - r + 1) * (m - r + 1)));
	return 0;
}