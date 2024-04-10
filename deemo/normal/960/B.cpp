#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, a[2][MAXN], k[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k[0] >> k[1];
	for (int w = 0; w < 2; w++) 
		for (int i = 0; i < n; i++) 
			cin >> a[w][i];
	for (int w = 0; w < 2; w++)
		while (k[w]--){
			int ind = 0;
			for (int i = 1; i < n; i++)
				if (abs(a[0][i]-a[1][i]) > abs(a[0][ind]-a[1][ind]))
					ind = i;
			if (a[0][ind] > a[1][ind])
				a[0][ind]--;
			else
				a[0][ind]++;
		}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += 1ll*(a[0][i]-a[1][i])*(a[0][i]-a[1][i]);
	cout << ans << endl;
	return 0;
}