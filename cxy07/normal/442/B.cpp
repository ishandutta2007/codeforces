//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define FILE
//#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 5010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

int n;
double p[MAXN],P = 0;
double sum1[MAXN],sum2[MAXN],pro1[MAXN],pro2[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return (x > 0 ? 1 : -1);
}

signed main () {
#ifdef FILE
#endif
	while(scanf("%d",&n) != EOF) {
		P = 0;
		bool flag = false;
		pro1[0] = 1;
		for(int i = 1;i <= n; ++i) scanf("%lf",&p[i]);
		sort(p + 1,p + n + 1);	
		for(int i = 1;i <= n; ++i) {
			if(!dcmp(p[i] - 1)) {
				flag = true;
				break;
			}
			pro1[i] = pro1[i - 1] * (1 - p[i]);
			sum1[i] = sum1[i - 1] + p[i] / (1 - p[i]);
		}
		if(flag) {
			puts("1");
			continue;
		}
		pro2[n + 1] = 1;
		sum2[n + 1] = 0;
		for(int i = n;i >= 1; --i) {
			pro2[i] = pro2[i + 1] * (1 - p[i]);
			sum2[i] = sum2[i + 1] + p[i] / (1 - p[i]);
		}
		for(int l = 0;l <= n; ++l) {
			for(int r = l + 1;r <= n + 1; ++r) 
				P = max(P,pro1[l] * pro2[r] * (sum1[l] + sum2[r]));
		}
		printf("%.9lf\n",P);
	}
	return 0;
}