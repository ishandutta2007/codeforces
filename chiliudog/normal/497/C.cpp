#include <bits/stdc++.h>
#define X first
#define Y second
#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
using LL = long long;
using PII = pair<int,int>;

const int N = 200005;
int n, m;
struct Node {
	int i, x, y, k;
	bool operator <(const Node &rhs) const {
		return y<rhs.y;
	}
};
vector<Node> ns;
multiset<Node> S;
int ans[N];

int main() {
	// judge();
	scanf("%d", &n);
	FI(i,1,n) {
		int x, y; scanf("%d%d", &x, &y);
		ns.push_back({i,x,y,0});
	}
	scanf("%d", &m);
	FI(i,1,m) {
		int x, y, k; scanf("%d%d%d", &x, &y, &k);
		ns.push_back({i,x,y,k});
	}
	sort(ns.begin(), ns.end(), [](const Node &a, const Node &b) {
		return a.x!=b.x ? a.x<b.x : a.k>b.k;
			});
	for (auto &t: ns) {
		if (t.k) S.insert(t);
		else {
			auto p = S.lower_bound(t);
			if (p==S.end()) return !printf("NO\n");
			auto z = *p;
			S.erase(p);
			if (--z.k) S.insert(z);
			ans[t.i] = z.i;
		}
	}
	printf("YES\n");
	FI(i,1,n) printf("%d ", ans[i]);
}