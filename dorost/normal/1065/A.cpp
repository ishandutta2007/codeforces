#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll q, s, a, b, c;
	cin >> q;
	while(q--) {
        cin >> s >> a >> b >> c;
        cout << ((s / c) / a) * b + s / c << endl;
	}
}