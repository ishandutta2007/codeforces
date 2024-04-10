/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int n;
	cin >> n;
	int ans [10];
	int a[10];
	int mn = 1000000000ll;
	for (int i = 1; i < 50; i++){
		for (int j = 0; j < 10; j++)
			a[j] = i;
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < j; k++)
				a[k] ++;
			int mul = 1;
			for (int k = 0; k < 10; k++){
				mul *= a[k];
			}
			if (mul >= n){
				int sum = 0;
				for (int k = 0; k < 10; k++){
					sum += a[k];
				}
				if (sum < mn){
					mn = sum;
					for (int k = 0; k < 10; k++){
						ans[k] = a[k];
					}
				}
			}
			for (int k = 0; k < j; k++)
				a[k] --;
		}
	}
	string s = "codeforces";
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < ans[i]; j++){
			cout << s[i];
		}
	}
}