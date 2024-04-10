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
int h,m,s,t1,t2;
double aaaaa[7],x,y;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(h);read(m);read(s);read(t1);read(t2);
	h%=12; t1%=12; t2%=12;
	x=(double)t1/12; y=(double)t2/12;
	bool ok=0;
	aaaaa[1]=((double)h*3600+m*60+s)/43200;
	aaaaa[2]=((double)m*6+(double)s*0.1)/360;
	aaaaa[3]=(double)s/60;
	sort(aaaaa+1,aaaaa+3+1);
	if (aaaaa[1]<x&&x<aaaaa[2]&&aaaaa[1]<y&&y<aaaaa[2]) ok=1;
//	printf("%d\n",ok);
	if (aaaaa[2]<x&&x<aaaaa[3]&&aaaaa[2]<y&&y<aaaaa[3]) ok=1;
//	printf("%d\n",ok);
	if ((aaaaa[1]>x||x>aaaaa[3])&&(aaaaa[1]>y||y>aaaaa[3])) ok=1;
//	printf("%d\n",ok);
	printf("%s",ok?"YES":"NO");
	return 0;
}