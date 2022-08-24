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
	string s;
	cin >> s;
	int smaller = 300;
	for (int i=0; i < s.size(); ++i){
		int S = s[i] - '0';
		if (smaller < S) cout << "Ann\n";
		else cout << "Mike\n";
		smaller = min(smaller, S);
	}

}