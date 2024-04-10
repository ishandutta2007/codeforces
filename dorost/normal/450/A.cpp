#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, m;
	cin >> n >> m;
	int a[n], mini, maxi = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = (a[i] + m - 1) / m;
		if(a[i] >= maxi){
			maxi = a[i];
			mini = i + 1;
		}
	}
	cout << mini;
}