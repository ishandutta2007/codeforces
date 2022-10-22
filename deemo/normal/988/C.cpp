#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n;
vector<int> vec[MAXN];
map<int, pii> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		vec[i].resize(t);
		int sm = 0;
		for (int j = 0; j < t; j++)
			cin >> vec[i][j], sm += vec[i][j];
		for (int j = 0; j < t; j++)
			if (mp.count(sm - vec[i][j])){
				int z = sm - vec[i][j];
				if (mp[z].F == i) continue;
				
				cout << "YES\n";
				cout << mp[z].F+1 << " " << mp[z].S+1 << "\n";
				cout << i+1 << " " << j+1 << "\n";
				return 0;
			}
			else
				mp[sm - vec[i][j]] = make_pair(i, j);
	}
	cout << "NO\n";
	return 0;
}