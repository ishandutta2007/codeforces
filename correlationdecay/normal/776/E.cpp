#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define maxn 300009
using namespace std;
const long long MOD = 1000000007LL;
const long long INF = 1e17;
long long phi(long long n){
	long long ans = n;
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0)
				n /= i;
			ans = ans - ans / i;
		}
	}
	if(n != 1){
		ans = ans - ans / n;
	}
	return ans;
}
int main(){
	long long n, k;
	cin >> n >> k;
	k = (k + 1) / 2;
	for(int i = 0 ;i < k ; i++){
		long long ans = phi(n);
		if(n == ans){
			n = ans;
			break;
		}
		if(ans == 1){
			n = 1;
			break;
		}
		n = ans;
	}
	cout << n % MOD << endl;
	return 0;
}