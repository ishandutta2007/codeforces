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
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i=0; i < n; ++i) {
		cin >> v[i];
	}

	ll a = 0, b = 0;
	for (int i=0; i < n; ++i) {
		if (i%2) {
			a += v[i] / 2;
			b += v[i] - (v[i] / 2);
		}
		else{
			b += v[i] / 2;
			a += v[i] - (v[i] / 2);
		}
	}

	cout << min(a, b);


}