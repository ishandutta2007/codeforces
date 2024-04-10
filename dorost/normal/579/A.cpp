#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int x, ans = 0;
	cin >> x;
	while (x){
		int i;
		for (i = 1; i <= x; i *= 2){}
		i /= 2;
		x -= i;
		ans++;
	}
	cout << ans;
}