#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ll n, a, b, c, max = 0;
	cin >> n >> a >> b >> c;
	for (int i = 0; i <= n / a; i++){
		for (int j = 0; j <= n / b; j++){
			if((n - (i * a + j * b)) % c == 0 && (i * a + j * b) <= n){
				int k = (n - (i * a + j * b)) / c;
				ll s = i + j + k;
				if(s > max)						
					max = s;
			}
		}
	}
	cout << max;
}