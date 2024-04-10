#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string a, b;
	cin >> n >> a >> b;
	int cost = 0;
	for(int i = 1; i < n; ++i) {
		if(a[i] != b[i] && a[i] == b[i-1] && a[i-1] == b[i]) {
			++cost;
			swap(a[i], a[i-1]);
		}
	}
	for(int i = 0; i < n; ++i) {
		cost += a[i] != b[i];
	}
	cout << cost << "\n";


}