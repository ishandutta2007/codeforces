#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const int MAXN = 1e5 + 20;
const ld PI = 3.141592653589793238462;

int n;
ll xx, yy, x[MAXN], y[MAXN];

ld dis(ld a, ld b, ld c, ld d){return	(a - c) * (a - c) + (b - d) * (b - d);}

ld get(ld a, ld b, ld c, ld d){
	ld ret = 1e18;
	if (a > c)	swap(a, c), swap(b, d);

	if (a == c){
		ld e = 0, f = d - b;
		ld sz = c - a, sz2 = d - b;
		for (int i = 0; i < 150; i++){
			ld m1 = (ld(2.0) * e + f)/ ld(3.0);
			ld m2 = (ld(2.0) * f + e)/ ld(3.0);
			
			ld aa = dis(xx, yy, a + (m1/sz2) * sz, b + m1), bb = dis(xx, yy, a + (m2/sz2) * sz, b + m2);
			if (aa > bb)
				e = m1;
			else
				f = m2;
		}
		ret = dis(xx, yy, a + (e/sz2) * sz, b + e);
	}
	else{
		ld e = 0, f = c - a;
		ld sz = c - a, sz2 = d - b;
		for (int i = 0; i < 150; i++){
			ld m1 = (ld(2.0) * e + f)/ ld(3.0);
			ld m2 = (ld(2.0) * f + e)/ ld(3.0);
			
			ld aa = dis(xx, yy, a + m1, b + m1/sz * (sz2)), bb = dis(xx, yy, a + m2, b + m2/sz * (sz2));
			if (aa > bb)
				e = m1;
			else
				f = m2;
		}
		ret = dis(xx, yy, a + e, b + e/sz * sz2);
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(18);
	cin >> n >> xx >> yy;
	ld mx = 0;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		mx = max(mx, dis(xx, yy, x[i], y[i]));
	}
	
	ld mn = 1e18;
	for (int i = 0; i < n; i++)
		mn = min(mn, get(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]));
	mx -= mn;
	cout << PI * (ld)mx << "\n";
	return	0;
}