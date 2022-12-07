#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234;
int n, T; 
struct info {
	int a, t, i;
	void in(int ii) {
		a = read(); t = read(); i = ii;
	}
}p[MaxN], q[MaxN]; int qn;

bool chk(int x) {
	qn = 0;
	for(int i = 1; i <= n; i++) if(p[i].a >= x) q[++qn] = p[i];
	sort(q + 1, q + qn + 1, [&] (info a, info b) {return a.t < b.t; });
	int j = 0, c = 0;
	for(int i = 1; i <= qn; i++) {
		if(j + q[i].t > T) break;
		j += q[i].t; c++;
	}
	return c >= x;
}

int main() {
	int i;
	n = read(); T = read();
	for(i = 1; i <= n; i++) p[i].in(i);
	int L = 0, R = n, ans = 0;
	while(L <= R) {
		int mid = L + R >> 1;
		if(chk(mid))
			L = mid + 1, ans = mid;
		else
			R = mid - 1;
	}	
	
	cout << ans << endl;
	qn = 0;
	for(int i = 1; i <= n; i++) if(p[i].a >= ans) q[++qn] = p[i];
	sort(q + 1, q + qn + 1, [&] (info a, info b) {return a.t < b.t; });
	int j = 0, c = 0;
	vector<int> res; res.clear();
	for(int i = 1; i <= qn; i++) {
		if(j + q[i].t > T) break;
		j += q[i].t; res.PB(q[i].i); if(res.size() == ans) break;
	}
	
	printf("%d\n", res.size());
	for(auto x : res) printf("%d ", x);
	return 0;
}