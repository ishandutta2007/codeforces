#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
bool lucky(int n){
	bool f = true;
	while(n){
		if(n % 10 != 4 && n % 10 != 7){
			f = false;
			break;
		}
		n /= 10;
	}
	return f;
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(n % i == 0 && lucky(n / i)){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}