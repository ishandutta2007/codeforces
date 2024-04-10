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

const int MAXN = 5010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n,m;
int a[MAXN];
int buk[MAXN],ans[MAXN],now;
vector<int> v;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int trans(int x) {
	int flag = 1;
	if(x < 0) {
		flag = -1;
		x *= -1;
	}
	for(int i = 2;i * i <= x; ++i) {
		while(x % (i * i) == 0) x /= (i * i);
	}
	return x * flag;
}

int Getid(int x) {
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1;i <= n; ++i) {
		read(a[i]);
		a[i] = trans(a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i = 1;i <= n; ++i) 
		if(a[i]) a[i] = Getid(a[i]);
	for(int i = 1;i <= n; ++i) {
		now = 0;
		for(int j = 1;j <= n; ++j) buk[j] = 0;
		for(int j = i;j <= n; ++j) {
			if(!a[j]) {
				if(!now) ans[1]++;
				else ans[now]++;
				continue;
			} 
			if(!(buk[a[j]]++)) now++;
			ans[now]++;
		}
	}
	for(int i = 1;i <= n; ++i) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}