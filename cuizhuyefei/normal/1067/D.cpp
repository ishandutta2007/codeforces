#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000;
int n,a[N],b[N];ll t,now;double p[N],M,val;
struct dot{
	double x,y;
	dot(double X=0,double Y=0){x=X;y=Y;}
}s[N],ss[N];
dot operator -(dot a, dot b){return dot(a.x-b.x,a.y-b.y);}
double Cross(dot a, dot b){return a.x*b.y-a.y*b.x;}
bool cmp(const dot &a,const dot &b){return a.x<b.x;}

int main() {
	read(n);read(t);
	rep(i,1,n)scanf("%d%d%lf",&a[i],&b[i],&p[i]);
	rep(i,1,n)M=max(M,b[i]*p[i]);
	rep(i,1,n)s[i].x=p[i],s[i].y=p[i]*a[i]-p[i]*M;
	sort(s+1,s+n+1,cmp);int len=1;ss[len]=s[len];
	rep(i,2,n){
		while(len>1&&Cross(ss[len]-ss[len-1],s[i]-ss[len-1])>=0)len--;
		ss[++len]=s[i];
	}
	n=len;rep(i,1,len)s[i]=ss[i];s[n+1].y=-1e18;
	//s[1..n] t
	rep(i,1,len){
		double b[3][3]={{1-s[i].x,s[i].x*M,s[i].y+s[i].x*M},{0,1,1},{0,0,1}};
	//	printf("qaq %.10lf %.10lf\n",s[i].x,s[i].y);
		double mi[35][3][3]={0};memcpy(mi[0],b,sizeof(b));
		rep(j,1,34){
			rep(x,0,2)rep(z,0,2)rep(y,0,2)mi[j][x][y]+=mi[j-1][x][z]*mi[j-1][z][y];
		}
		per(j,34,0)if(now+(1LL<<j)<=t){
			double nxt=mi[j][0][0]*val+mi[j][0][1]*now+mi[j][0][2];
			if(s[i].y+s[i].x*(M*(now+(1LL<<j)+1)-nxt)>=s[i+1].y+s[i+1].x*(M*(now+(1LL<<j)+1)-nxt)){
				now+=1LL<<j;val=nxt;
			}
		}
		if(now+1<=t&&(s[i].y+s[i].x*(M*(now+1)-val))>=(s[i+1].y+s[i+1].x*(M*(now+1)-val)))
			val=b[0][0]*val+b[0][1]*now+b[0][2],now++;
	}
//	cerr<<now<<endl;
	printf("%.10lf",val);
	return 0;
}