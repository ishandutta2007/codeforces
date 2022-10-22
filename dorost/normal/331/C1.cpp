#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, ans = 0;
	cin >> n;
	while(n){
		int m = n, max = 0;
		while(m){
			if(max < m % 10){
				max = m % 10;
			}
			m /= 10;
		}
		n -= max;
		ans ++;
		cerr << n << endl;
	}
	cout << ans;
}