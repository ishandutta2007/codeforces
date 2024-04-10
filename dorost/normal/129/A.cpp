#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n], x = 0, ans = 0;
	for(int i = 0 ; i < n; i++){
		cin >> a[i];
		x = (x + a[i]) % 2;
	}
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == x){
			ans ++;
		}
	}
	cout << ans;
}