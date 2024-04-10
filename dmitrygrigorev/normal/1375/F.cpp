#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int read() {
	int x;
	cin >> x;

	if (x==0) exit(0);
	return x - 1;

}

bool good(vector<int> &v, int last) {

	if (v[last] == max({v[0], v[1], v[2]})) return true;
	return false;

}

main(){
#ifdef LOCAL
	//freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];

	cout << "First" << endl;

	cout << 1 << endl;

	int x = read();
	v[x]++;

	while (!good(v, x)) {

		int a = min({v[0], v[1], v[2]});
		int b = max({v[0], v[1], v[2]});
		int mid;
		for (int i = 0; i < 3; ++i) {
			if (v[i] != a && v[i] != b) mid = v[i];
		}

		cout << mid-a << endl;
		x = read();
		v[x] += (mid-a);
	}

	int a = min({v[0], v[1], v[2]});
	int b = max({v[0], v[1], v[2]});
	int mid;
	for (int i = 0; i < 3; ++i) {
		if (v[i] != a && v[i] != b) mid = v[i];
	}

	cout << mid-a + 2 * (b-mid) << endl;
	x = read();
	v[x] += mid-a + 2 * (b-mid);

	a = min({v[0], v[1], v[2]});
	b = max({v[0], v[1], v[2]});
	for (int i = 0; i < 3; ++i) {
		if (v[i] != a && v[i] != b) mid = v[i];
	}

	cout << mid-a << endl;
	read();
	assert(0);
}