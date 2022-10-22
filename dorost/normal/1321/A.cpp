#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int a[n], b[n], n1 = 0, n2 = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
		if (b[i] != a[i]){
			if (b[i] == 1){
				n1 ++;
			}else{
				n2 ++;
			}
		}
	}
	if (n2 == 0){
		cout << -1;
	}else{
		cout << (n1 + n2) / n2;
	}
}