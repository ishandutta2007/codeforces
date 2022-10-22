#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int max_n = 1e7 + 10;
const int MOD = 1e9 + 7;

int n;
long long d[max_n];

int main(){
	cin >> n;
	d[0] = 1, d[1] = 0;
	long long sum = 3;
	for (int i = 2; i <= n; i++){
		d[i] = sum;
		sum = (sum * 2) % MOD;
		sum = (sum + d[i - 1] * 3) % MOD;
	}
	cout << d[n] << endl;
	return	0;
}