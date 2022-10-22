/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1012345;
int cnt[M], cnt2[M];

int32_t main(){
	int n;
	cin >> n;
	vector <int> v[n];
	int ans = n * n;
	vector <pair <int, int>> rem;
	for (int i = 0; i < n; i++){
		int l;
		cin >> l;
		for (int j = 0; j < l; j++){
			int x;
			cin >> x;
			v[i].push_back(x);
		}
		reverse (v[i].begin(), v[i].end ());
		if (!is_sorted(v[i].begin(), v[i].end ())){
//			ans += n;
		}else{
			rem.push_back({v[i][0], v[i][v[i].size() - 1]});
			cnt[v[i][0]] ++;
			cnt2[v[i][v[i].size() - 1]] ++;
		}
		reverse (v[i].begin(), v[i].end ());
	}
	for (int i = 1; i < M; i++){
		cnt2[i] += cnt2[i - 1];
	}
	/* for (int i = 0; i < 10; i++)
		cout << cnt2[i] << ' ';
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << ' ';
	cout << endl; */
	for (int i = 0; i < M; i++){
		ans -= cnt2[i] * cnt[i];
	}
	cout << ans;
}