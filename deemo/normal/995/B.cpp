#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, a[MAXN], b[MAXN], c[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(b, -1, sizeof(b));
	for (int i = 0; i < 2*n; i++){
		cin >> a[i], a[i]--;
		if (b[a[i]] == -1)
			b[a[i]] = i;
		else
			c[a[i]] = i;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++){
			if (c[i] < b[j] || c[j] < b[i]) continue;
			if (b[i] < b[j] && c[j] < c[i]) ans += 2;
			else if (b[j] < b[i] && c[i] < c[j]) ans += 2;
			else ans++;
		}
	cout << ans << endl;
	return 0;
}