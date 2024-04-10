#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 300010;
int n, k;
vi a;
int d[nmax];
vi m[1000010];

class SegmentTree {
private:
    int n;  
	vector<int> st, A;
	int left(int p) {return p << 1;};
	int right(int p) {return (p << 1) + 1;}

	void build(int p, int L, int R) {
		if (L == R) st[p] = L;
		else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		if (L >= i && R <= j) return st[p];

		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return (A[p1] >= A[p2]) ? p1 : p2;
	}

public:
    void init(const vector<int> &_A) {
		A = _A; n = (int) A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
    
	int rmq(int i, int j) {return rmq(1, 0, n - 1, i, j);}
} smt;

ll run(int l, int r) {
     if (l > r) return 0;
     if (l == r) return 1;
     int mid = smt.rmq(l, r);
     ll res = 0;
     if (mid - l < r - mid) {
         FOR(i, l, mid + 1) {
                int h = (d[i] + a[mid]) % k;
                int u = lower_bound(m[h].begin(), m[h].end(), r + 2) - m[h].begin();
                int v = lower_bound(m[h].begin(), m[h].end(), mid + 1) - m[h].begin();
                if (v < sz(m[h]) && m[h][v] <= r + 1) res += u - v;
         }
     }
     else {
         FOR(i, mid + 1, r + 2) {
                int h = (k + d[i] - (a[mid] % k)) % k;
                int u = lower_bound(m[h].begin(), m[h].end(), mid + 1) - m[h].begin();
                int v = lower_bound(m[h].begin(), m[h].end(), l) - m[h].begin();
                if (v < sz(m[h]) && m[h][v] <= mid) res += u - v;
         }
     }
     return res + run(l, mid - 1) + run(mid + 1, r);
}

void solve() {
     ms(d, 0);
     scanf("%d%d", &n, &k);
     m[0].push_back(0);
     FOR(i, 0, n) {int p; scanf("%d", &p); a.push_back(p); d[i + 1] = (d[i] + p) % k; m[d[i + 1]].push_back(i + 1);}
     smt.init(a);
     printf("%I64d", run(0, n - 1) - n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}