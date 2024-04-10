#include <bits/stdc++.h>
    /** Interface */

inline int readChar();
template <class T = int> inline T getInt(); 

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T getInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const int mod = int(1e9) + 7, szz = 2 * 1024 * 1024;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}

ll n, k[szz], x[2], y[2], xx[2], yy[2];
string s;

int fc(int nu, int xl, int yl, int xr, int yr) {
	int ans = 0;
	forn (i, nu)
		if (x[i] >= xl && xx[i] <= xr && y[i] >= yl && yy[i] <= yr)
			ans++;
	re ans;
}

void get(int nu, int xl, int yl, int xr, int yr) {
 	int lx = xl - 1, rx = xr;
 	while (rx - lx > 1) {
 		int mid = (lx + rx) / 2;
 		cout << "? " << xl << " " << yl << " " << mid << " " << yr << endl;
 		int k;
 		cin >> k;
 		k -= fc(nu, xl, yl, mid, yr);
 		if (k == 0) {
 			lx = mid;
 		}
 		else
 			rx = mid;
 	} 
 	xx[nu] = rx;
 	lx = xl, rx = xr + 1;
 	while (rx - lx > 1) {
 		int mid = (lx + rx) / 2;
 		cout << "? " << mid << " " << yl << " " << xr << " " << yr << endl;
 		int k;
 		cin >> k;
 		k -= fc(nu, mid, yl, xr, yr);
 		//cout << lx << " " << rx << endl;
 		if (k == 0) {
 			rx = mid;
 		}
 		else
 			lx = mid;
 	}
 	x[nu] = lx;
 	//cout << lx << endl;
 	int ly = yl - 1, ry = yr;
 	while (ry - ly > 1) {
 		int mid = (ly + ry) / 2;
 		cout << "? " << xl << " " << yl << " " << xr << " " << mid << endl;
 		int k;
 		cin >> k;
 		k -=  fc(nu, xl, yl, xr, mid);
 		if (k == 0) 
 			ly = mid;
 		else
 			ry = mid;
 	} 
 	yy[nu] = ry;
 	ly = yl, ry = yr + 1;
 	while (ry - ly > 1) {
 		int mid = (ly + ry) / 2;
 		cout << "? " << xl << " " << mid << " " << xr << " " << yr << endl;
 		int k;
 		cin >> k;
 		k -= fc(nu, xl, mid, xr, yr);
 		if (k == 0)
 			ry = mid;
 		else	
 			ly = mid; 
 	}
 	y[nu] = ly;
}

int main() {
	iostream::sync_with_stdio(0);// cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	int lx = 0, rx = n;
	while (rx - lx > 1) {
		int mid = (lx + rx) / 2;
		cout << "? " << 1 << " " << 1 << " " << mid << " " << n << endl;
		int k;
		cin >> k;
		if (k < 2) {
			lx = mid;
		}
		else
			rx = mid;
	}
	int ly = 0, ry = n;
	while (ry - ly > 1) {
		int mid = (ly + ry) / 2;
		cout << "? " << 1 << " " << 1 << " " << n << " " << mid << endl;
		int k;
		cin >> k;
		if (k < 2) {
			ly = mid;
		}
		else
			ry = mid;
	}
	bool ok = false;
	if (ry > 1) {
		cout << "? 1 1 " << n << " "  << ry - 1 << endl;
		int	k;
		cin >> k;
		if (k != 0)
			ok = true;
	}
	if (ok) {
		get(0, 1, 1, n, ry - 1);
	}
	else
		get(0, 1, 1, rx - 1, n);
	get(1, 1, 1, n, n);
	cout << "! " << x[0] << " " << y[0] << " " << xx[0] << " " << yy[0] << " "
		 << x[1] << " " << y[1] << " " << xx[1] << " " << yy[1] << endl;
	re 0;
}