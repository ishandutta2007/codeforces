#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 500;

int a[MAXN];
int c[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n/2; i++) cin >> a[i], a[i]--;
	sort(a, a + n/2);
	int ans = 1e9;
	for (int w = 0; w < 2; w++){
		int ret = 0;
		for (int i = w, j = 0; j < n/2; i += 2, j++){
			ret += abs(a[j] - i);
		}
		ans = min(ans, ret);
	}
	cout << ans << endl;
	return 0;
}