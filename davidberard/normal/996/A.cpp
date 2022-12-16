#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int bills[] = {1, 5, 10, 20, 100};
int bmax = 5;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	int ans = 0;
	for(int i=bmax-1;i>=0;--i) {
		ans += N/bills[i];
		N %= bills[i];
	}
	cout << ans << endl;
	return 0;
}