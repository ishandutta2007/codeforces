#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, i, j, x, y;

	cin >> t;

	auto prime = [&](int x){
		int i;
		for(i = 2; i * i <= x; i ++){
			if(x % i == 0) return 0;
		}
		return 1;
	};

	for(; t --; ){
		cin >> n;
		for(x = 0; ; x ++){
			if(!prime(x) && prime(x + (n - 1))) break;
		}
		for(y = 0; ; y ++){
			if(!prime(y) && prime(y + x * (n - 1))) break;
		}
		for(i = 0; i < n; i ++){
			for(j = 0; j < n; j ++){
				if(i == 0 && j == 0) cout << y << " ";
				else if(i == 0 || j == 0) cout << x << " ";
				else cout << 1 << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}