//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define double long double
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb emplace_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'
#define y1 _y1

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int pos[MAXN], fen[MAXN];
int opt[MAXN], L[MAXN], R[MAXN];
double X, Y, K[MAXN], B[MAXN], Ans;
vec<pii> tmp;
set<pii> S;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

struct NODE {
	double x, y, tan; int id;
	NODE(double _x = 0., double _y = 0., int i = 0) {
		x = _x, y = _y, id = i;
		tan = atan2(y, x);
	}
	bool operator == (const NODE &b) const {
		return fabs(x - b.x) < eps && fabs(y - b.y) < eps;
	}
	bool operator < (const NODE &b) const {return tan < b.tan;}
};

vec<NODE> cross;

void add(int x, int b) {
	for(; x <= (n << 1); x += lowbit(x))
		fen[x] += b;
}

int ask(int x) {
	int res = 0;
	for(; x; x -= lowbit(x)) res += fen[x];
	return res;
}

void init(double r) {
	cross.clear(); tmp.clear();
	for(int i = 1; i <= n; ++i) {
		double d = r * r + K[i] * K[i] * r * r - B[i] * B[i];
		if(d < 0) continue;
		d = sqrt(d);
		double x1 = (-K[i] * B[i] + d) / (1 + K[i] * K[i]);
		double y1 = x1 * K[i] + B[i];
		double x2 = (-K[i] * B[i] - d) / (1 + K[i] * K[i]);
		double y2 = x2 * K[i] + B[i];
		cross.pb(NODE(x1, y1, 2 * i - 1));
		cross.pb(NODE(x2, y2, 2 * i));
	}
	sort(cross.begin(), cross.end());
	/*for(int i = 1; i <= (n << 1); ++i) 
		pos[i] = fen[i] = opt[i] = L[i] = R[i] = 0;*/
	for(int i = 1; i <= (n << 1); ++i) fen[i] = opt[i] = 0;
	for(int i = 0; i < cross.size(); ++i) pos[cross[i].id] = i + 1;
	for(int i = 1; i <= n; ++i) {
		double dis = fabs(B[i]) / sqrt(K[i] * K[i] + 1.);
		if(dis > r) continue;
		int L1 = pos[2 * i - 1], R1 = pos[2 * i];
		if(L1 > R1) swap(L1, R1);
		tmp.pb(mp(L1, i)), tmp.pb(mp(R1, i));
		L[i] = L1, R[i] = R1;
	}
	sort(tmp.begin(), tmp.end());
	for(int i = tmp.size() - 1; ~i; --i)
		if(!opt[tmp[i].scd]) opt[tmp[i].scd] = i + 1;
}

int calc(double r) {
	int res = 0; init(r);
	for(int i = 0; i < tmp.size(); ++i) 
		if(opt[tmp[i].scd] != i + 1) {
			res += ask(opt[tmp[i].scd]) - ask(i);
			add(opt[tmp[i].scd], 1);
		}
	return res;
}

double c(int i, int j) {
	double x = (B[j] - B[i]) / (K[i] - K[j]);
	double y = K[i] * x + B[i];
	return sqrt(x * x + y * y);
}

void count(double r) {
	init(r);
	for(int i = 0, id; i < tmp.size(); ++i) 
		if(opt[tmp[i].scd] != i + 1) {
			id = tmp[i].scd;
			if(!S.size()) {S.insert(mp(R[id], id)); continue;}
			auto it = S.upper_bound(mp(L[id], id));
			if(it != S.end())
				while(it != S.end() && it->fst < R[id]) 
					Ans += c(id, it->scd), it++;
			S.insert(mp(R[id], id));
		}
}

signed main () {
#ifdef FILE
	freopen("CF607E.in", "r", stdin);
	freopen("CF607E.out", "w", stdout);
#endif
	read(n); scanf("%Lf%Lf", &X, &Y); read(m);
	X /= 1000., Y /= 1000.;
	for(int i = 1; i <= n; ++i) {
		read(K[i]), read(B[i]);
		K[i] /= 1000., B[i] /= 1000.;
		B[i] = B[i] - Y + K[i] * X;
	}
	X = Y = 0;
	double L = 0, R = 1e10, mid;
	if(calc(eps) >= m) return puts("0"), 0;
	while(fabs(R - L) > eps) {
		mid = (L + R) / 2.;
		if(calc(mid) < m) L = mid + eps;
		else R = mid;
	}
	count(R - 10 * eps);
	Ans += (m - calc(R - 10 * eps)) * R;
	printf("%.15Lf\n", Ans);
	return 0;
}