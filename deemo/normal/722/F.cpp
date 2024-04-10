#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int MAXK = 40 + 2;

int n, m;
vector<int>	vec[MAXN];
vector<pair<int, int>>	sec[MAXN];
int lst[MAXK], pt[MAXN];

bool ok(int a, int b, int c, int d){
	int g = __gcd(a, b);
	return c % g == d % g;
}

int get(int ind, int tl, int tr){
	int ret = 0;
	memset(lst, -1, sizeof(lst));
	for (int i = tl; i < tr; i++){
		int x = sec[ind][i].F, y = sec[ind][i].S;
		pt[x] = sec[ind][tl].F;
		for (int j = 0; j < MAXK; j++)
			if (~lst[j]){
				if (ok(vec[x].size(), j, y, sec[ind][i - (x - lst[j])].S))
					pt[x] = max(pt[x], pt[lst[j]]);
				else
					pt[x] = max(pt[x], lst[j] + 1);
			}

		ret = max(ret, x - pt[x] + 1);
		lst[vec[x].size()] = x;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int sz;	cin >> sz;
		vec[i].resize(sz);
		for (int j = 0; j < sz; j++)
			cin >> vec[i][j], vec[i][j]--, sec[vec[i][j]].push_back({i, j});
	}
	for (int i = 0; i < m; i++){
		int mx = 0;
		sort(sec[i].begin(), sec[i].end());
		for (int tl = 0; tl < sec[i].size();){
			int tr = tl + 1;
			while (tr < sec[i].size() && sec[i][tr - 1].F + 1 == sec[i][tr].F)	tr++;
			
			mx = max(mx, get(i, tl, tr));
			tl = tr;
		}
		cout << mx << "\n";
	}
	return 0;
}