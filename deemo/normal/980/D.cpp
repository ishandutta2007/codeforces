#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e3 + 10;

int n, a[MAXN];
vector<int> vec[MAXN];
map<vector<int>, int> mp; int sz;
int ans[MAXN];
int cnt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 0) continue;

		int fl = a[i] < 0? -1: -2;
		a[i] = abs(a[i]);

		for (int j = 2; j*j <= a[i]; j++) {
			int c = 0;
			while (a[i] % j == 0){
				c ^= 1;
				a[i] /= j;
			}
			if (c & 1)
				vec[i].push_back(j);
		}
		if (a[i] > 1)
			vec[i].push_back(a[i]);
		vec[i].push_back(fl);

		if (mp.count(vec[i]))
			a[i] = mp[vec[i]];
		else
			a[i] = mp[vec[i]] = ++sz;
	}

	for (int l = 0; l < n; l++) {
		memset(cnt, 0, sizeof(cnt));
		int c = 0;
		for (int r = l; r < n; r++){
			if (a[r]){
				if (!cnt[a[r]]) c++;
				cnt[a[r]]++;
			}
			ans[max(1, c)]++;
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << ans[i+1] << " ";
	cout << "\n";
	return 0;
}