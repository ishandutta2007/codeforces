#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, ans = 0, a;
	cin >> n >> a;
	int min = a, max = a;
	for(int i = 1; i < n; i++){
		cin >> a;
		if(a > max)
			max = a, ans++;
		if(a < min)
			min = a, ans++;
	}
	cout << ans;
}