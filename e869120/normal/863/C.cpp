#include<iostream>
#include<vector>
using namespace std;
long long p[3][3], a[3][3], b[3][3], ca, cb, n, dp[3][3], dc1[3][3], dc2[3][3];
int main() {
	cin >> n >> ca >> cb; int da = ca, db = cb; da--; db--;
	for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) { cin >> a[i][j]; a[i][j]--; } }
	for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) { cin >> b[i][j]; b[i][j]--; } }
	long long cnt = 0, ret1 = 0, ret2 = 0;
	while (true) {
		cnt++; 
		if (da != db) {
			if ((da == 2 && db == 1) || (da == 1 && db == 0) || (da == 0 && db == 2))ret1++;
			else ret2++;
		}
		if (dp[da][db] >= 1) {
			long long E1 = (ret1 - dc1[da][db]);
			long long E2 = (ret2 - dc2[da][db]);
			long long F = (cnt - dp[da][db]);
			long long R = (n - cnt) / F;
			long long A1 = ret1 + E1*R;
			long long A2 = ret2 + E2*R;
			for (int i = 0; i < n - cnt - R*F; i++) {
				int F1 = da, F2 = db; da = a[F1][F2]; db = b[F1][F2];
				if (da != db) {
					if ((da == 2 && db == 1) || (da == 1 && db == 0) || (da == 0 && db == 2))A1++;
					else A2++;
				}
			}
			cout << A1 << " " << A2 << endl;
			break;
		}
		dp[da][db] = cnt; dc1[da][db] = ret1; dc2[da][db] = ret2;
		if (cnt == n) { cout << ret1 << " " << ret2 << endl; break; }
		int F1 = da, F2 = db; da = a[F1][F2]; db = b[F1][F2];
	}
	return 0;
}