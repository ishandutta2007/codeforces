#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	int n;
	cin >> n;
	if (n == 1){
		cout << -1;
	}else if(n == 2){
		int a, b;
		cin >> a >> b;
		if (a == b){
			cout << -1;
		}else{
			cout << 1 << endl << 1;
		}
	}else{
		int a[n], min = 1e4, ans = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] < min){
				min = a[i];
				ans = i + 1;
			}
		}
		cout << 1 << endl << ans;
	}
}