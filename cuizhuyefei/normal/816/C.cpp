#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int N = 105;
int n,m,ans;
int a[N][N];
int res[100005][2];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int Line(int k) {
	int res=1000;
	rep(i,1,m) if (a[k][i]==0) return 0;
	else res=min(res,a[k][i]);
	return res;
}
int Col(int k) {
	int res=1000;
	rep(i,1,n) if (a[i][k]==0) return 0;
	else res=min(res,a[i][k]);
	return res;
}

bool solve1(){
	rep(i,1,n) rep(j,1,m) {
		int tmp=Line(i);
		if (tmp) {
			rep(k,1,tmp) {
				ans++; res[ans][0]=0;
				res[ans][1]=i;
			}
			rep(k,1,m) a[i][k]-=tmp;
		}
		if (a[i][j]) {
			tmp=Col(j);
			if (tmp<a[i][j]) return 0;
			rep(k,1,tmp) {
				ans++; res[ans][0]=1;
				res[ans][1]=j;
			}
			rep(k,1,n) a[k][j]-=tmp;
		}
	}
	return 1;
}
bool solve2(){
	rep(i,1,n) rep(j,1,m) {
		int tmp=Col(j);
		if (tmp) {
			rep(k,1,tmp) {
				ans++; res[ans][0]=1;
				res[ans][1]=j;
			}
			rep(k,1,n) a[k][j]-=tmp;
		}
		if (a[i][j]) {
			tmp=Line(i); //i not j
			if (tmp<a[i][j]) return 0;
			rep(k,1,tmp) {
				ans++; res[ans][0]=0;
				res[ans][1]=i;
			}
			rep(k,1,m) a[i][k]-=tmp;
		}
	//	printf("%d %d\n",i,j);
	//	rep(k,1,n){rep(l,1,m)printf("%d ",a[k][l]); puts("");}
	//	puts("");
	}
	return 1;
}
void print() {
	printf("%d\n",ans);
	rep(i,1,ans) {
		if (res[i][0]==0) printf("row "); else printf("col ");
		printf("%d\n",res[i][1]);
	}
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,n) rep(j,1,m) read(a[i][j]);
	if (n<=m) 
		if (solve1()) print();
		else puts("-1");
	else
		if (solve2()) print();
		else puts("-1");
	return 0;
}