#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, depth[MAXN], cnt[MAXN], ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int p; cin >> p, p--;
		depth[i] = depth[p] + 1;
	}
	for (int v = 0; v < n; v++)
		cnt[depth[v]]++;
	for (int i = 0; i < MAXN; i++)
		ans += cnt[i]&1;
	cout << ans << endl;
	return 0;
}