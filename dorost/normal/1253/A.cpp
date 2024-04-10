#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 100123;
int a[N], b[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int lst = 0, fst = 1;
		bool h = true;
		bool f = true;
		int cnt = 0, x = -1;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++){
			cin >> b[i];
			if (a[i] == b[i])
				continue;
			if (b[i] < a[i])
				h = false;
			if (f && a[i] != b[i])
				fst = i, f = false, x = b[i] - a[i];
			if (a[i] != b[i])
				lst = i, cnt++;
			if (b[i] - a[i] != x)
				h = false;
		}
//		cout << fst << ' ' << lst << ' ' << cnt << endl;
		if (lst - fst + 1 == cnt && h)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}