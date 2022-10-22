//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct String {
	string L,R;
	int len;
	bool de;
	char top;
	void Insert(char c) {
		if(c != top) de = (c < top);
		top = c;
		len++;
		L = top + L;
		if(L.size() > 10) {
			if(R.size() < 2) {
				R = L.back() + R;
				L.pop_back();
				R = L.back() + R;
			}
			L.pop_back();
		}
	}
} a[MAXN];

int n,m;
char s[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void print(int id) {
	printf("%d ",a[id].len);
	if(a[id].len > 10) {
		cout << a[id].L.substr(0,5) << "..." << a[id].R.substr(a[id].R.size() - 2,2) << endl;
	} else cout << a[id].L << endl;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for(int i = n;i; --i) {
		if(i < n && s[i] == s[i + 1]) {
			a[i] = a[i + 2];
			if(a[i].top > s[i] || (a[i].top == s[i] && a[i].de)) {
				a[i].Insert(s[i]);
				a[i].Insert(s[i]);
			}
		} else {
			a[i] = a[i + 1];
			a[i].Insert(s[i]);
		}
	
	}
	for(int i = 1;i <= n; ++i) print(i);
	return 0;
}