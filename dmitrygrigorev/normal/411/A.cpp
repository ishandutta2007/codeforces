#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string kek = "Too weak";
string tet = "Correct";

main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (s.size() < 5) {
		cout << kek;
		exit(0);
	}

	bool a = false, b = false, c = false;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') a = true;
		if (s[i] >= 'A' && s[i] <= 'Z') b = true;
		if (s[i] >= '0' && s[i] <= '9') c = true;
	}
	if (a && b && c) cout << tet;
	else cout << kek;

}