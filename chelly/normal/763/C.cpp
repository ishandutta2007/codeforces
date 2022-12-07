#include<bits/stdc++.h>
using namespace std;
const int N(222222);
int a[N];
bool f[N];
int pw(int x, int n, int modulo) {
	int res(1);
	while(n) {
		if(n & 1)
			res = (long long)res * x % modulo;
		x = (long long)x * x % modulo;
		n /= 2;
	}
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
	}
	bool flag(false);
	if(n * 2 >= m) {
		flag = true;
		for(int i(1); i <= n; i++)
			f[a[i]] = true;
		n = 0;
		for(int i(0); i < m; i++) 
			if(!f[i])
				a[++n] = i;
	}
	//for(int i(1); i <= n; i++)
	//	printf("a[%d] = %d\n", i, a[i]);
	int delta, strt;
	if(n == 1 || n == 0) {
		delta = 1;
		strt = a[1];
	}else {
		int k((a[2] - a[1] + m) % m);
		set<int> st;
		for(int i(1); i <= n; i++)
			st.insert(a[i]);
		int cnt(0);
		for(int i(1); i <= n; i++) {
			cnt += st.count((a[i] - k + m) % m);
			cnt += st.count((a[i] + k) % m);
		}
		delta = (long long)k * pw(n - (cnt / 2), m - 2, m) % m;
		int x(a[1]);
		while(st.count((x - delta + m) % m))
			x = (x - delta + m) % m;
		strt = x;
		//f(n >= 100000) cout << k << ' ' << cnt << ' ' << strt << ' ' << delta << endl;
	}
	set<int> st;
	for(int i(1); i <= n; i++)
		st.insert((strt + (i - 1ll) * delta) % m);
	bool ok(true);
	for(int i(1); i <= n; i++) {
		ok &= st.count(a[i]) == 1;
	}
	if(!ok)
		printf("-1\n");
	else {
		if(flag) {
			printf("%d %d\n", (strt - delta + m) % m, (m - delta) % m);
		}else {
			printf("%d %d\n", strt, delta);
		}
	}
}