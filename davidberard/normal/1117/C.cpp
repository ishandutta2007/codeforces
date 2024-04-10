#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int amt[256];
int dx[100100];
int dy[100100];
ll X1,Y1, X2, Y2;
ll n;
string s;

ll bs() {
	ll lo = 0, hi = 2e18;
	while(lo<hi) {
		ll m = (1+lo+hi)/2;
		ll base = m/n;
		ll rem = m%n;
		ll xh = X1+(ll)dx[n]*base+dx[rem];
		ll yh = Y1+(ll)dy[n]*base+dy[rem];
		ll d = abs(xh-X2)+abs(yh-Y2);
		if(d > m) {
			lo = m;
		} else {
			hi = m-1;
		}
	}
	return lo+1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> n;
	cin >> s;
	int xx = 0, yy = 0;
	for(int i=0;i<s.size();++i) {
		char c = s[i];
		switch(c) {
			case 'U': yy++; break;
			case 'D': yy--; break;
			case 'L': xx--; break;
			case 'R': xx++; break;
			default: assert(false); break;
		}
		dx[i+1] = xx;
		dy[i+1] = yy;
	}
	ll ans = bs();
	cout << (ans > 1000000000000000000 ? -1 : ans) << endl;

	return 0;
}