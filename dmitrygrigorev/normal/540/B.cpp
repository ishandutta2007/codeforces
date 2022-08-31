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
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;

	vector<int> v(k);
	int sum = 0;
	for (int i = 0; i < k; ++i){
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < k; ++i) if (v[i] >= y) cnt++;
	int rem = n-k;

	int must = max(0, (n+1)/2 - cnt);

	if (rem < (n+1)/2 - cnt || must * y + (rem - must) + sum > x) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < must; ++i) cout << y << " ";
	for (int i = 0; i < rem - must; ++i) cout << "1 ";

}