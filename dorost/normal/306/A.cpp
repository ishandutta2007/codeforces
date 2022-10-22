#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;
	int a[k];
	for (int i = 0; i < k; i++){
		a[i] = n / k;
	}
	for (int i = k - 1; i > k - 1 - n % k; i--){
		a[i]++;
	}
	for (int i = 0; i < k; i++){
		cout << a[i] << ' ';
	}
}