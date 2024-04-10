#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define MOD 1000000007



int main(){
	Int n, k;
	cin >> n >> k;
	if(n == 1){
		if(k == 0)cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	if(n / 2 > k){
		cout << -1 << endl;
		return 0;
	}
	Int m = k - (n / 2) + 1;
	Int p = 1;
	for(int i = 1;i < n / 2;i++){
		while(m == p || m == p + 1 || m * 2 == p || m * 2 == p + 1)p++;
		cout << p << " " << p + 1 << " ";
		p+=2;
	}
	cout << m << " " << m * 2 ;
	if(n % 2 == 1)cout << " " << 999999999;
	cout << endl;
	return 0;
	
}