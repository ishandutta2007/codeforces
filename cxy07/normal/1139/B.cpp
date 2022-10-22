//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 1e9 + 10;

long long n,now = INF,ans;
long long a[MAXN];

int main () {
	cin >> n;
	for(int i = 1;i <= n; ++i)
		cin >> a[i];
	for(int i = n;i >= 1; --i) {
		if(now > a[i]) now = a[i];
		else now--;
		if(now <= 0) break;
		ans += now;
	}
	cout << ans << endl;
	return 0;
}