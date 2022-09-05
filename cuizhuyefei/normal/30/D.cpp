#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 233333;
int n,k,x[N],y;
ll sqr(int x){return 1LL*x*x;}
int Abs(int x) {return x>0?x:-x;}
double getans(int l, int r) {
	if (l>r) return 0;
	return x[r]-x[l]+sqrt(1LL*y*y+min(sqr(x[n+1]-x[l]),sqr(x[n+1]-x[r])));
}
double getdis(int pos) {
	return sqrt(1LL*y*y+sqr(x[n+1]-pos));
}
int main() { //freopen("1.in","r",stdin);
	read(n);read(k); rep(i,1,n+1) read(x[i]); read(y); int pos=x[k];
	sort(x+1,x+n+1); int Left=0;
	if (k==n+1) {printf("%.12lf",getans(1,n)); return 0;}
	rep(i,1,n) if (x[i]==pos) {Left=i-1; rep(j,i,n-1) x[j]=x[j+1]; n--; break;} 
	x[n+1]=x[n+2]; double ans=getans(1,n)+getdis(pos); //!!!!!!!!
//	printf("%d %d \n",pos,Left);rep(i,1,n) printf("%d ",x[i]); puts("");
	ans=min(ans,Abs(pos-x[1])+getdis(x[1])+getans(Left+1,n));
	rep(i,Left+1,n) ans=min(ans,Abs(pos-x[1])+Abs(x[i]-x[1])+getdis(x[i])+getans(i+1,n));
	rep(i,Left+1,n) ans=min(ans,Abs(pos-x[i])+Abs(x[1]-x[i])+getdis(x[1])+getans(i+1,n));
	ans=min(ans,Abs(pos-x[n])+getdis(x[n])+getans(1,Left));
	rep(i,1,Left) ans=min(ans,Abs(pos-x[n])+Abs(x[i]-x[n])+getdis(x[i])+getans(1,i-1));
	rep(i,1,Left) ans=min(ans,Abs(pos-x[i])+Abs(x[n]-x[i])+getdis(x[n])+getans(1,i-1));
	printf("%.12lf\n",ans);
	return 0;
}