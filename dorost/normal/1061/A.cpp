#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, s;
	cin >> n >> s;
	for (ll i = n; i > 0; i++){
        if (s < 1){
            cout << abs(n - i);
            break;
        }
        s -= n;
	}
}