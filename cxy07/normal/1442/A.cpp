//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T, n, m;
int a[MAXN], l[MAXN], r[MAXN];
int Minl[MAXN], Minr[MAXN];
bool flag;

signed main () {
	cin >> T;
	while(T--) {
		cin >> n;
		flag = true;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		Minl[0] = Minr[n + 1] = INF;
		for(int i = 1; i <= n; ++i) Minl[i] = min(Minl[i - 1], a[i]);
		for(int i = n; i >= 1; --i) Minr[i] = min(Minr[i + 1], a[i]);
		l[1] = a[1], r[1] = 0;
		for(int i = 2; i <= n; ++i) {
			if(l[i - 1] + r[i - 1] <= a[i]) {
				l[i] = l[i - 1]; 
				r[i] = a[i] - l[i];
			} else {
				r[i] = r[i - 1];
				l[i] = a[i] - r[i];
			}
		}
		puts(l[n] >= 0 ? "YES" : "NO");
	}
	return 0;
}