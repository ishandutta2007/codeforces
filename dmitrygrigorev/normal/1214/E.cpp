#include <bits/stdc++.h>
#define ll long long
#define db long double

using namespace std;
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];
	vector<pair<int, int> > arr;
	for (int i=0; i < n; ++i){
		arr.push_back({v[i], i});
	}
	sort(arr.begin(), arr.end(), greater<pair<int, int> > ());
	for (int i=0; i < n-1; i++){
		int A = arr[i].second, B = arr[i+1].second;
		cout << 2*A+1 << " " << 2*B+1 << "\n";
	}
	vector<int> cur;
	for (int i=0; i < n; i++){
		int index = arr[i].second;
		cur.push_back(2*index);
	}
	for (int i=0; i < n; i++){
		int dist = arr[i].first;
		int index = i+dist-1;
		int I = arr[i].second;
		cout << cur[index]+1 << " " << 2*I+2 << "\n";
		if (index + 1 == cur.size()) cur.push_back(2*I+1);
	}
}