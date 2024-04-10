#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, m, s[2], v, t[2][MAXN];

int get(int a, int b, int c, int d, int pos, int sp = 1){
	int ret = abs(b - d);
	if (b > d)
		swap(b, d);

	if (pos < b)
		ret += b-pos<<1;
	else if (pos > d)
		ret += pos - d<<1;
	
	ret += (abs(a-c) + (sp - 1))/ sp;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s[0] >> s[1] >> v;
	for (int w = 0; w < 2; w++)
		for (int i = 0; i < s[w]; i++)
			cin >> t[w][i];

	int q; cin >> q;
	while (q--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int ans = 1e9;
		if (a == c)
			ans = abs(b - d);
		else{
			if (s[0]){
				int pos = upper_bound(t[0], t[0] + s[0], max(b, d)) - t[0];
				if (pos < s[0])
					ans = min(ans, get(a, b, c, d, t[0][pos]));
				if (pos)
					ans = min(ans, get(a, b, c, d, t[0][pos-1]));
			}
			if (s[1]){
				int pos = upper_bound(t[1], t[1] + s[1], max(b, d)) - t[1];
				if (pos < s[1])
					ans = min(ans, get(a, b, c, d, t[1][pos], v));
				if (pos)
					ans = min(ans, get(a, b, c, d, t[1][pos-1], v));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}