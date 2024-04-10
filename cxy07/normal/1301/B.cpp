//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10; 
const int INF = 2e9;

int T,k,n,m;
int a[MAXN],L,R;

int main () {
	cin >> T;
	while(T--) {
		cin >> n;
		L = INF,R = 0,m = 0;
		for(register int i = 1;i <= n; ++i) 
			cin >> a[i]; 
		for(register int i = 1;i <= n; ++i) {
			if(a[i] == -1) {
				if(i - 1 && a[i - 1] != -1) L = min(L,a[i - 1]),R = max(R,a[i - 1]);
				if(i + 1 <= n && a[i + 1] != -1) L = min(L,a[i + 1]),R = max(R,a[i + 1]); 
			}
		}
		k = (L + R) >> 1;
		for(register int i = 1;i <= n; ++i) {
			if(a[i] == -1) a[i] = k;
			if(i - 1) m = max(m,abs(a[i] - a[i - 1]));
		}
		cout << m << ' ' << k << endl;
	}
	return 0;
}