/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int an = -1;
		for (int i = 0; i < n; i++){
			if (a[i] != 1){
				an = i;
				break;
			}
		}
		if (an == -1){
			cout << (n % 2 ? "First" : "Second") << '\n';
		}else{
			cout << (an % 2 ? "Second" : "First") << '\n';
		}
	}
}