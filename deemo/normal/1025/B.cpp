#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 150e3 + 10;

int n;
ll aa[MAXN], bb[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll g = 0;
	for (int i = 0; i < n; i++){
		ll a, b; cin >> a >> b;
		aa[i] = a, bb[i] = b;
		ll x = a*b;
		g = __gcd(g, x);
	}
	if (g == 1)
		cout << "-1\n";
	else {
		for (int i = 0; i < n; i++){
			ll temp = __gcd(aa[i], g);
			if (temp != 1)
				g = temp;
			else
				g = __gcd(bb[i], g);
		}
		cout << g << "\n";
	}
	return 0;
}