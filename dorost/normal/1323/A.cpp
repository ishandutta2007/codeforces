#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){	
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		bool f = false, h = false;
		int an1 = -1, an2 = -1, an3 = -1;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] % 2 == 0){
				f = true;
				an1 = i + 1;
			}
		}
		if (f){
			cout << 1 << endl << an1 << endl;
		}else{
			for (int i = 0; i < n - 1; i++){
				if ((a[i] + a[i + 1]) % 2 == 0){
					h = true;
					an2 = i + 1;
					an3 = i + 2;
				}
			}
			if (h){
				cout << 2 << endl << an2 << ' ' << an3 << endl;
			}else{
				cout << -1 << endl;
			}
		}
	}
}