/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];
pair <int, int> pm[N], sm[N];

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i =0 ; i < n; i++)
			cin >> a[i];
		bool f  =false;
		for (int i = 1; i < n - 1; i++){
			if (a[i - 1] < a[i] && a[i] > a[i + 1]){
				cout << "Yes\n";
				f = true;
				cout << i << ' ' << i + 1 << ' ' << i + 2 << endl;
				break;
			}
		}
		if (!f)
			cout << "No\n";
	}
}