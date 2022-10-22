//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 110;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,cnt,pa,pb;
int a[MAXN],b[MAXN];

signed main () {
	cin >> n;
	for(register int i = 1;i <= n; ++i) {
		cin >> a[i];
		pa += a[i];
	}
	for(register int i = 1;i <= n; ++i) {
		cin >> b[i];
		if(a[i] && (!b[i])) cnt++;
		pb += b[i];
	}
	if(pa > pb) return puts("1"),0;
	if(!cnt) return puts("-1"),0;
	cout << ceil((double)(pb - pa + 1) / cnt) + 1 << endl;
	return 0;
}