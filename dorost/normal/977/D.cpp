#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
#define int long long
pair <pair <int, int>, int> a[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].S;
		int x = a[i].S;
		while (x % 2 == 0){
			x /= 2;
			a[i].F.F ++;
		}
		while (x % 3 == 0){
			x /= 3;
			a[i].F.S ++;
		}
		a[i].F.S = 100 - a[i].F.S;
	}
	sort(a, a + n);
	for (int i = 0;  i < n; i++)
		cout << a[i].S << ' ';
}