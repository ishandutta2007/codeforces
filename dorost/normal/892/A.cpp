#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int x, a[n];
	ll sum = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		sum += x;
	}
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	if(sum <= a[n - 1] + a[n - 2]){
		cout << "YES";
	}else{
		cout << "NO";
	}
}