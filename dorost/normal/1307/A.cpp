#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		int a[n];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 1; i < n; i++){
			while (a[i] >= 1 && d >= i){
				a[i] -= 1;
				a[0] += 1;
				d -= i;
			}
		}
		cout << a[0] << endl;
	}
}