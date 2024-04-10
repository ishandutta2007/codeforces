/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 52;
int fib[N];

int32_t main(){
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < N; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
//	cerr << fib[N - 1];
	int n;
	cin >> n;
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			for (int k = j; k < N; k++){
				if (fib[i] + fib[j] + fib[k] == n){
					return cout << fib[i] << ' ' << fib[j] << ' ' << fib[k], 0;
				}
			}
		}
	}
	cout <<  "I'm too stupid to solve this problem";
}