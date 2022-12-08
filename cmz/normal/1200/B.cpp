#include<bits/stdc++.h>
using namespace std;
int T, n;
int kkk;
int kkkkkkkkkk;
long long m, k, a[1005];
int main() {
	cin >> T; int flg=1;
	while (T--){
		cin >> n >> m >> k;
		flg =1;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) {
			if (a[i] + k >= a[i + 1]) 
				m += a[i]-max(0LL, a[i + 1] - k);
			else if (a[i] + m < a[i + 1] - k) {
				puts("NO");
				flg = false;
				break;
			} else  m -= a[i + 1] - k - a[i];
		}
		if (flg) puts("YES");
	}
	return 0;
}