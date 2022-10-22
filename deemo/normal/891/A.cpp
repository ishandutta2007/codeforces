#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bool fl = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 1)
			fl = 1;
	}
	if (fl){
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (a[i] > 1)
				ans++;
		cout << ans << endl;
		return 0;
	}
	int mn = 1e9;
	for (int i = 0; i < n; i++){
		int cur = a[i], cnt = 0;
		for (int j = i+1; j < n && cur > 1; j++){
			cur = __gcd(cur, a[j]);
			cnt++;
		}
		if (cur == 1)
			mn = min(mn, cnt);
	}
	if (mn > 1e8)
		cout << "-1\n";
	else
		cout << mn+(n-1) << endl;
	return 0;
}