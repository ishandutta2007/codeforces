//Where are you, hatter?

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, mx[MAXN];
vector<int> vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		vec[i].resize(m);
		sec[i].resize(m);
		for (int j = 0; j < m; j++)	cin >> vec[i][j];
	}
	for (int i = n-1; ~i; i--)
		for (int j = 0; j < m; j++){
			if (i == n-1)
				sec[i][j] = 1;
			else if (vec[i][j] <= vec[i+1][j])
				sec[i][j] = sec[i+1][j]+1;
			else
				sec[i][j] = 1;
			mx[i] = max(mx[i], sec[i][j]);
		}

	int q;	cin >> q;
	while (q--){
		int l, r;	cin >> l >> r, l--;
		if (mx[l] >= r-l)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}