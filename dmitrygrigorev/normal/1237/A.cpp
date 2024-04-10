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
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cur = 0;
	for (int i=0; i < n; ++i){
		bool neg = false;
		int x;
		cin >> x;
		if (x < 0){
			x *= -1;
			neg = true;
		}
		if (x%2==0){
			x /= 2;
			if (!neg) cout << x << "\n";
			else cout << -x << "\n";
			continue;
		}
		x/=2;
		if (cur && !neg) x++;
		if (!cur && neg) x++;
		if (!neg) cout << x << "\n";
		else cout << -x << "\n";
		cur = 1-cur;
	}

}