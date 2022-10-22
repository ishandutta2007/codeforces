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

int n,m,ans = 1;
int pr[MAXN],cnt,les = 1;
bool np[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void sieve(int siz) {
	for(int i = 2;i <= siz; ++i) {
		if(!np[i]) pr[++cnt] = i;
		for(int j = 1;j <= cnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

void GetMin() {
	for(int i = 1,x,now = 1;i <= les; ++i) {
		now = 1;
		printf("B %d\n",pr[i]);
		fflush(stdout);
		read(x);
		while(1) {
			now *= pr[i];
			if(now > n) break;
			printf("A %d\n",now);
			fflush(stdout);
			read(x);
			fflush(stdout);
			if(!x) break;
			ans *= pr[i];
		}
	}
}

void GetMax() {
	int siz = sqrt(cnt - les),pre;
	int blk = ceil((double)(cnt - les + 1) / siz);
	bool flag = false;
	printf("A 1\n");
	fflush(stdout);
	read(pre);
	fflush(stdout);
	for(int i = 1,tot,now;i <= blk; ++i) {
		tot = 0;
		for(int p = les + (i - 1) * siz + 1,x; p <= min(cnt,les + i * siz); ++p) {
			printf("B %d\n",pr[p]);
			fflush(stdout);
			read(x);
			fflush(stdout);
			tot += x;
		}
		printf("A 1\n");
		fflush(stdout);
		read(now);
		fflush(stdout);
		if(now + tot > pre) {
			assert(now + tot == pre + 1);
			for(int p = les + (i - 1) * siz + 1,x; p <= min(cnt,les + i * siz); ++p) {
				printf("A %d\n",pr[p]);
				fflush(stdout);
				read(x);
				fflush(stdout);
				if(x) {
					ans *= pr[p];
					flag = true;
					break;
				}
			}
		} else {
			assert(now + tot == pre);
			pre = now;
		}
		if(flag) break;
	}
	return;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	if(n == 1) {
		printf("C %d\n",1);
		return 0;
	}
	sieve(n);
	for(int i = 1;i <= cnt; ++i) {
		if(pr[i] > sqrt(n)) break;
		les = i;
	}
	GetMin();
	GetMax();
	printf("C %d\n",ans);
	fflush(stdout);
	return 0;
}