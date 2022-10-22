#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	int n;
	cin >> n;
	for (int i = sqrt(n); i > 0; i--){
		if (n % i == 0){
			cout << i << ' ' << n / i;
			break;
		}
	}
}