#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef complex<ld> PT;

#define F first
#define S second
#define X real()
#define Y imag()

const int ON = 0, LEFT = 1, RIGHT = -1, BACK = -2, FRONT = 2, IN = 3, OUT = -3;
const ld EPS = 1e-12;

inline bool Geq(ld a, ld b){ return a - b > -EPS; }
inline bool Grt(ld a, ld b){ return a - b > EPS; }
inline bool Leq(ld a, ld b){ return a - b < EPS; }
inline bool Lss(ld a, ld b){ return a - b < -EPS; }
inline bool Equ(ld a, ld b){ return abs(a-b) < EPS; }

pii p[2][4];
PT pp[2][4];

int relpos(PT a, PT b, PT c){
	b -= a; c -= a; c /= b;
	if (Grt(c.imag(), 0)) return LEFT;
	if (Lss(c.imag(), 0)) return RIGHT;
	if (Lss(c.real(), 0)) return BACK;
	if (Grt(c.real(), 1)) return FRONT;
	return ON;
}

int side(PT a, PT b, PT c){
	b -= a, c -= a;
	ld cr = (c/b).Y;
	return Grt(cr, 0) ? 1 : (Lss(cr, 0) ? -1 : 0);
}

bool bad(int x){return x == BACK || x == FRONT;}

bool check(int t, PT aa){
	int last = relpos(pp[t][3], pp[t][0], aa);
	if (last == ON) return true;
	if (bad(last)) return false;

	for (int i = 0; i < 3; i++) {
		int temp = relpos(pp[t][i], pp[t][i+1], aa);
		if (temp == ON) return true;
		if (bad(temp)) return false;
		if (temp != last) return false;
	}
	return true;
}

bool intersect(PT a, PT b, PT c, PT d){
	int as = side(c, d, a), bs = side(c, d, b), cs = side(a, b, c), ds = side(a, b, d);
	if (as && as == bs || cs && cs == ds) return false;
	else if (as || bs || cs || ds) return true;
	for (int j = 0; j < 2; j++, swap(a, c), swap(b, d)){
		ld mx = min(a.X, b.X), Mx = max(a.X, b.X), my = min(a.Y, b.Y), My = max(a.Y, b.Y);
		for (int k = 0; k < 2; k++, swap(c, d))
			if (Geq(c.X, mx) && Leq(c.X, Mx) && Geq(c.Y, my) && Leq(c.Y, My))
				return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int w = 0; w < 2; w++)
		for (int i = 0; i < 4; i++) {
			cin >> p[w][i].F >> p[w][i].S;
			pp[w][i] = PT(p[w][i].F, p[w][i].S);
		}

	for (int w = 0; w < 2; w++)
		for (int i = 0; i < 4; i++)
			if (check(!w, pp[w][i])){
				cout << "YES\n";
				return 0;
			}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (intersect(pp[0][i], pp[0][i==3?0:i+1], pp[1][j], pp[1][j==3?0:j+1])){
				cout << "YES\n";
				return 0;
			}
	cout << "NO\n";
	return 0;
}