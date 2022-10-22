#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	if (n > 0)
		cout << n;
	else if(n >= -10){
		cout << 0;
	}else if(n % 10 < (n % 100) / 10){
		cout << n / 10;	
	}else{
		cout << n / 100 * 10 + n % 10;
	}
}