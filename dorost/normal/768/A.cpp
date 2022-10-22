#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n;
	cin >> n;
	int a[n], mini = 10000 * 100000 + 1, maxi = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mini = min(a[i], mini);
		maxi = max(a[i], maxi);
	}
	int cntmin = 0, cntmax = 0;
	for (int i = 0; i < n; i++){
		cntmin += (a[i] == mini);
		cntmax += (a[i] == maxi);
	}
	cout << max(n - cntmin - cntmax, 0);
}