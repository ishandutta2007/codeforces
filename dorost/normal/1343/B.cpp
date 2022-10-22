#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
vector <int> a, b;

int32_t main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		a.clear();
		b.clear();
		if (n % 4){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n / 2 - 1; i++){
			a.push_back(i * 2 + 1);
			b.push_back(i * 2 + 2);
		}
		n /= 2;
		a.push_back(n * 5 - 1);
		b.push_back(n * 4);
		for (int i = 0; i < b.size(); i++){
			cout << b[i] << ' ';
		}
		for (int i = 0; i < a.size(); i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}