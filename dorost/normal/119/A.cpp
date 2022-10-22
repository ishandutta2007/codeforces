#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a, b, n;
	cin >> a >> b >> n;
	for (int i = 0; true; i++){
		if (i % 2 == 0){
			if (n < 0)
				return cout << 0, 0;
			n -= __gcd(a, n);
		}else{
			if (n < 0)
				return cout << 1, 0;
			n -= __gcd(b, n);
		}
	}
}