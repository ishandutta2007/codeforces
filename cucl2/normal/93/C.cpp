/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int N;
string t[33];
int a[33];

string inline e_x(int val) {
	string res = "eax";
	res[1] += val;
	return res;
}

bool inline dfs(int lim, int now) {
	if(a[now] > N) return 0;
	if(now == lim) {
		if(a[now] != N) return 0;
		cout << lim << endl;
		cont(i, lim) cout << t[i] << endl;
		return 1;
	}
	loop(i, now + 1) range(j, 1, 8, j) {
		a[now + 1] = a[i] * j;
		if(a[now + 1] > N) continue;
		if(now + 1 == lim && a[now + 1] != N) continue;
		t[now + 1] = "lea " + e_x(now + 1) + ", [" + char('0' + j) + "*" + e_x(i) + "]";
		if(dfs(lim, now + 1)) return 1;
	}
	loop(i, now + 1) loop(j, now + 1) range(k, 1, 8, k) {
		a[now + 1] = a[i] + a[j] * k;
		if(a[now + 1] > N) continue;
		if(now + 1 == lim && a[now + 1] != N) continue;
		t[now + 1] = "lea " + e_x(now + 1) + ", [" + e_x(i) + " + " + char('0' + k) + "*" + e_x(j) + "]";
		if(dfs(lim, now + 1)) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &N);
	a[0] = 1;
	loop(i, 30) if(dfs(i, 0)) return 0;
}
/**
 * 
 *   i  i  1
 */