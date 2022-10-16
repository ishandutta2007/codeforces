#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 2e12+1;

int n, k, a[200005], b[200005];

struct cmp{
	bool operator()(auto p1, auto p2) {
		int q1 = p1.F, q2 = p2.F;
		int r1 = p1.S.F, r2 = p2.S.F;
		return (q1 > q2) || (q1 == q2 && r1*p2.S.S > r2*p1.S.S);
	}
};

bool ok(int m) {
	priority_queue<pair<int, pair<int32_t, int32_t>>, vector<pair<int, pair<int32_t, int32_t>>>, cmp> pq;
	for(int i=0;i<n;i++)
		pq.push({a[i]/b[i], {a[i]%b[i], b[i]}});
	for(int i=0;i<k-1;i++) {
		auto p = pq.top(); pq.pop();
		int s = p.S.F + m;
		p.F += s / p.S.S;
		p.S.F = s % p.S.S;
		pq.push(p);
		p = pq.top();
		if(p.F*p.S.S+p.S.F - p.S.S * (i + 1) < 0)
			return false;
	}
	return true;
}

int32_t main()
{
	IO_OP;
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	int l = 0, r = INF;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) {
			r  = m - 1;
		} else {
			l = m + 1;
		}
	}
	if(l == INF+1)
		cout << -1 << endl;
	else
		cout << l << endl;
}