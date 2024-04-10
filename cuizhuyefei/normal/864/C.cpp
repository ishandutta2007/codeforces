#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 500050;
int a,b,f,k,now,ans;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int ok() {
	rep(i,1,k) { //(i&1) 0; else a;
		if (i==k) {
			if (i&1) {
				if (f>now) return -1;
				if (a>now) {ans++; if ((a-f)>b) return -1;}
			}
			else {
				if (a-f>now) return -1;
				if (a>now) {ans++; if (f>b) return -1;}
			}
		}
		else {
			if (i&1) {
				if (f>now) return -1;
				if (a+a-f>now) {ans++; now=b-(a-f);}
				else now-=a;
			}
			else {
				if (a-f>now) return -1;
				if (a+f>now) {ans++; now=b-(f);}
				else now-=a;
			}
		}
	}
	return 1;
}
int main() {
	//6 10 2 4
	read(a); read(b); read(f); read(k); now=b;
	if (ok()<1) puts("-1");
	else printf("%d",ans);
	return 0;
}