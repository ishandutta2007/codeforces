#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int gcd(int x, int y){
	if (y==0) return x;
	return gcd(y, x%y);
}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];
	vector<int> res = {};
	int D = 1;
	vector<int> c = v;
	while (true){
		n = v.size();
		vector<int> even, odd;
		for (int i=0; i < n; ++i){
			if (v[i] % 2) even.push_back(v[i]);
			else odd.push_back(v[i]);
		}
		if (even.size() > res.size()){
			res = {};
			for (int i=0; i < even.size(); ++i) res.push_back(even[i]*D);
		}
		if (!odd.size()) break;
		int G = odd[0];
		for (int i=1; i < odd.size(); ++i) G = gcd(G, odd[i]);
		for (int i=0;i<odd.size();++i) odd[i] /= G;
		D *= G;
		v = odd;
	}
	set<int> used;
	for (int i=0;i<res.size();++i) used.insert(res[i]);
	cout << c.size()-res.size() << "\n";
	for (int i=0;i<c.size();++i) if (!used.count(c[i])) cout << c[i] << " ";

}