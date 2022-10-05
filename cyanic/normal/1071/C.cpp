#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a),_E=(b); i<=_E; i++)
#define per(i,a,b) for (int i=(a),_E=(b); i>=_E; i--)
#define REP(i,a,b) for (int i=0,_E=(n); i<_E; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int maxn = 200005;
struct node { int x, y, z; } ans[maxn];
int a[maxn], j, k, n, cnt, cur;
set<int> s;

inline bool check(node a, node b, node c) {
	return a.y == b.x
		&& a.z == b.y
		&& b.y == c.x
		&& b.z == c.y;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) {
		scanf("%d", &a[i]);
		if (a[i]) s.insert(i);
	}
	
	rep (i, 1, n - 2) if (a[i]) {
		s.erase(i); a[i] = 0;
		if (s.empty() || 2 * (*s.begin()) > i + n)
			j = (i + n) / 2;
		else
			j = *s.begin();
		k = 2 * j - i;
		
		ans[++cnt] = (node) {i, j, k};
		
		if (a[j]) s.erase(j), a[j] = 0;
		else s.insert(j), a[j] = 1;
		
		if (a[k]) s.erase(k), a[k] = 0;
		else s.insert(k), a[k] = 1;
	}
	
//	puts("");
//	rep (i, 1, n) printf("%d ", a[i]);
//	puts("");
	
	if (!a[n-1] && a[n] && n >= 7) {
		ans[++cnt] = (node) {n - 6, n - 3, n};
		ans[++cnt] = (node) {n - 6, n - 5, n - 4};
		ans[++cnt] = (node) {n - 5, n - 4, n - 3};
	}
	else if (a[n-1] && !a[n] && n >= 8) {
		n--;
		ans[++cnt] = (node) {n - 6, n - 3, n};
		ans[++cnt] = (node) {n - 6, n - 5, n - 4};
		ans[++cnt] = (node) {n - 5, n - 4, n - 3};
	}
	else if (a[n] && a[n-1] && n >= 8) {
		ans[++cnt] = (node) {n - 6, n - 3, n};
		ans[++cnt] = (node) {n - 6, n - 5, n - 4};
		ans[++cnt] = (node) {n - 5, n - 4, n - 3};
		n--;
		ans[++cnt] = (node) {n - 6, n - 3, n};
		ans[++cnt] = (node) {n - 6, n - 5, n - 4};
		ans[++cnt] = (node) {n - 5, n - 4, n - 3};
	}
	else if (a[n] || a[n-1]) return puts("NO"), 0;
	
	rep (i, 1, cnt)
		if (i <= cnt - 2 && check(ans[i], ans[i+1], ans[i+2])) {
			ans[++cur] = (node) {ans[i].x, ans[i+1].y, ans[i+2].z};
			i += 2;
		}
		else
			ans[++cur] = ans[i];

	printf("YES\n%d\n", cur);
	rep (i, 1, cur)
		printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);	

	return 0;
}