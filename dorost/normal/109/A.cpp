#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
bool lucky(ll n){
	bool f = true;
	while(n){
		int m = n % 10;
		if(m != 4 && m != 7){
			f = false;
			break;
		}
		n /= 10;
	}
	return f;
}
int main(){
	int n,cnt4 = 0,cnt7 = 0;
	cin >> n;
	while(n % 7){
		if(n < 0){
			cout << -1;
			return 0;
		}
		n -= 4;
		cnt4++;
	}
	while(n){
		n -= 7;
		cnt7++;
	}
	while(cnt4--){
		cout << 4;
	}
	while(cnt7--){
		cout << 7;
	}
}