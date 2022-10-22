#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
pair <int, int> a[N];
vector <int> v;
int b[N];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = n - i;
		b[i] = a[i].F;
	}
	sort(a, a + n);
	reverse(a, a + n);
//	for (int i = 0; i < n; i++)
//		a[i].S = i;
	int t;
	cin >> t;
	while (t--){
		int m, p;
		cin >> m >> p;
		v.clear();
		for (int i = 0; i < m; i++){
			v.push_back(n - a[i].S);
		}
		sort (v.begin(), v.end());
		cout << b[v[p - 1]] << endl;
	}
}