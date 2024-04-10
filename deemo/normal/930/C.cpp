#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, m, cnt[MAXN], a[MAXN], ans[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (n--){
		int l, r; cin >> l >> r, l--;
		cnt[l]++;
		cnt[r]--;
	}
	int sm = 0;
	for (int i = 0; i < m; i++){
		sm += cnt[i];
		a[i] = sm;
	}
	vector<int> lis;
	for (int i = 0; i < m; i++){
		int pos = upper_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if (pos == lis.size())
			lis.push_back(a[i]);
		else
			lis[pos] = a[i];
		ans[i] = pos+1;
	}
	lis.clear();
	int res = 0;
	for (int i = m-1; ~i; i--){
		int pos = upper_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if (pos == lis.size())
			lis.push_back(a[i]);
		else
			lis[pos] = a[i];
		ans[i] += pos;
		res = max(res, ans[i]);
	}
	cout << res << "\n";
	return 0;
}