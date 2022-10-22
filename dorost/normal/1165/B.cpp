#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a + n);
	int h = 1;
	for (int i = 0; i < n; i++){
//		cout << i << ' ' << a[i] << ' ' << h << endl;
		if (h <= a[i]){
			h++;
		}
	}
	cout << h - 1;
}