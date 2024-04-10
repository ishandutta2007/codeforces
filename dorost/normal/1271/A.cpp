#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie(), cout.tie()

int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << max(min(a, d) * e + min({b, c, d - min(a, d)}) * f, min({b, c, d}) * f + min(a, d - min({b, c, d})) * e);
}