#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int n;
string s, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> t;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' && t[i] == '0'){
			c1++;
		}
		if (s[i] == '0')
			c2++;
		if (s[i] == '0' && t[i] == '0') c3++;
		if (s[i] == '1') c4++;
	}

	ll ans = 1ll*c1*c2;
	ans += 1ll*c3*c4;
	ans -= 1ll*c1*c3;
	cout << ans << endl;
	return 0;
}