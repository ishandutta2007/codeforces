//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int b[MAXN], L, R;
set<int> S;
bool flag = true;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) {
		read(n); S.clear(); L = 0, R = 0;
		for(int i = 1; i <= n; ++i) read(b[i]);
		S.insert(b[1]); flag = true;
		for(int i = 2; i <= n; ++i) {
			if(b[i] == b[i - 1]) {L++, R++; continue;}
			if(b[i] > b[i - 1]) {
				R += 2;
				auto it = S.find(b[i - 1]);
				if(it == (--S.end())) {R--; S.insert(b[i]); continue;} 
				it++;
				if(*it == b[i]) continue;
				if(*it < b[i]) {flag = false; break;}
				if(*it > b[i]) {R--; S.insert(b[i]);}
			} else {
				L += 2;
				auto it = S.find(b[i - 1]);
				if(it == S.begin()) {L--; S.insert(b[i]); continue;}
				it--;
				if(*it == b[i]) continue;
				if(*it > b[i]) {flag = false; break;}
				if(*it < b[i]) {L--; S.insert(b[i]);}
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}