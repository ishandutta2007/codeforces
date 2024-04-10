#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

ld PI = acosl(-1);

ld dot(ld a, ld b, ld c, ld d) {
	return a*c + b*d;
}

ld cross(ld a, ld b, ld c, ld d) {
	return a*d - b*c;
}

ld angle(ld a, ld b, ld c, ld d) {
	return atan2(cross(a,b,c,d),dot(a,b,c,d));
}

int n,a;
ld r;
ld ang(int i, int j) {
	ld xi = cosl(2*PI*i/n)-1;
	ld yi = sinl(2*PI*i/n);
	ld xj = cosl(2*PI*j/n)-1;
	ld yj = sinl(2*PI*j/n);
	return angle(xi,yi,xj,yj);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a;
	r = a/ld(180)*PI;
	int q,w;
	ld e = 1000000000;
	for(int i = 1; i < n-1; ++i) {
		int lo = i+1, hi = n-1;
		while(hi - lo < 0) {
			int md = (lo+hi)/2;
			if(ang(i,md) <= r) lo = md;
			else hi = md;
		}
		int b = -1;
		if(abs(ang(i,lo)-r) < abs(ang(i,hi)-r)) b = lo;
		else b = hi;
		ld score = abs(ang(i,b)-r);
		if(score < e) {
			q = i;
			w = b;
			e = score;
		}
		// cout << q+1 << " 1 " << w+1 << endl;
	}
	cout << w+1 << " 1 " << q+1 << "\n";
}