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
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=0; i < t; i++){
		int a, b, n;
		cin >> a >> b >> n;
		if (n%3==0) cout << a << "\n";
		else if (n%3==1) cout << b << "\n";
		else cout << (a^b) << "\n";
	}
}