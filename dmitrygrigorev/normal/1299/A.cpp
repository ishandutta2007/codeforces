#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<int> sum(n);

	for (int i = 0; i < 30; ++i) {
		vector<int> tut;
		for (int j = 0; j < n; ++j) {
			if ((1<<i)&v[j]) tut.push_back(j);
		}
		if (tut.size() == 1) sum[tut[0]] += (1<<i);
	}

	int mx = 0, ind = 0;
	for (int i = 0; i < n; ++i) {
		if (sum[i] > mx) {
			mx = sum[i];
			ind = i;
		}
	}

	swap(v[0], v[ind]);
	for (int i = 0; i < n; ++i) cout << v[i] << " ";

}