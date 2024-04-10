#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		int f = false, h = false;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] % 2 == 1){
				f++;
			}else {
				h++;
			}
		}
		cout << (f && h || f % 2 == 1 ? "YES" : "NO") << endl;
	}
}