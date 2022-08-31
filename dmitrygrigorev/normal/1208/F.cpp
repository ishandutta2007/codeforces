#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
const int N = (1<<21);
const int LG=21;
pair<int, int> b[N];
pair<int, int> merg(pair<int, int> &a, pair<int, int> &b){
	if (a.second > b.second){
		return {max(b.second, a.first), a.second}; 
	}
	if (a.second < b.second){
		return {max(a.second, b.first), b.second};
	}
	return {max(a.first, b.first), a.second};
}
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	for (int i=0; i < N; i++) b[i] = {-2, -1};
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; i++) cin >> v[i];
	for (int i=0; i < n; i++){
		b[v[i]].first = b[v[i]].second;
		b[v[i]].second = i;
	}
	for (int i=N-1; i >= 0; i--){
		for (int j=0; j < LG; j++){
			int ba = (1<<j)&i;
			if (ba!=0) continue;
			int V = i + (1<<j);
			b[i] = merg(b[i], b[V]);
		}
	}
	//cout << b[6].first << endl;
	int cur = 0;
	for (int i=LG-1; i >= 0; i--){
		//cout << cur << endl;
		int var = cur + (1<<i);
		bool can = false;
		for (int j=0; j < n; j++){
			int T = var ^ (var&v[j]);
			if (b[T].first > j) can = true;
		}
		if (can) cur=var;
	}
	cout << cur << endl;
}