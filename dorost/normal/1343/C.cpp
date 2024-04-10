#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], n;
bool f[N];
vector <int> v;
const int INF = (1e9 + 10) * -1;

int32_t main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] < 0){
				f[i] = false;
			}else{
				f[i] = true;
			}
		}
		if (n == 1){
			cout << a[0] << endl;
			continue;
		}
		int mx = a[0];
		for (int i = 1; i < n; i++){
			if (f[i] != f[i - 1]){
				v.push_back(max(mx, a[i - 1]));
				mx = a[i];
			}else{
				if (a[i] > mx)
					mx = a[i];
			}
		}
		v.push_back(mx);
		int sum = 0;
		for (int i = 0; i < v.size(); i++){
	//		cout << v[i] << ' ';
			sum += v[i];
		}
	//	cout << endl;
		cout << sum << endl;
	}
}