#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, R;
	cin >> N;
	cin >> R;
	vector<int> val(1<<N, 0);
	for(auto& ii : val) cin >> ii;
	ll sum = 0;
	for(auto& ii : val) sum += ii;
	cout << fixed << setprecision(10);
	cout << (ld) sum/(1<<N) << "\n";
	for(int i=0;i<R;++i) {
		int a ,b;
		cin >> a;
		cin >> b;
		sum -= val[a];
		sum += val[a] = b;
		cout << (ld) sum/(1<<N) << "\n";
	}
	return 0;
}