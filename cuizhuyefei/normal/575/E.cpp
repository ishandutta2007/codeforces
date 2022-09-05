#include<bits/stdc++.h>
#define x first
#define y second
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
const int N = 866666,mx=1e5;
int n;Pii s[N],sta[N];int len,top;
void ins(int x, int y){s[++len]=Pii(min(max(x,0),mx),min(max(y,0),mx));}
inline double getlen(Pii a){return sqrt(1LL*a.x*a.x+1LL*a.y*a.y);}
inline ll Cross(Pii a, Pii b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
Pii operator -(Pii a, Pii b){return Pii(a.x-b.x,a.y-b.y);}
double Abs(double x){return x>0?x:-x;}
bool cmp(Pii a, Pii b){
	a=a-s[1];b=b-s[1];ll t=1LL*a.x*b.y-1LL*a.y*b.x;
	return t?t>0:getlen(a)<getlen(b);
}
int main() {
	int v;read(n);
	rep(i,1,n){
		int x,y;read(x),read(y),read(v);
		if(x-v>=0)ins(x-v,y);else ins(0,y+(v-x)),ins(0,y-(v-x));
		if(y-v>=0)ins(x,y-v);else ins(x+(v-y),0),ins(x-(v-y),0);
		if(x+v<=mx)ins(x+v,y);else ins(mx,y+(v-mx+x)),ins(mx,y-(v-mx+x));
		if(y+v<=mx)ins(x,y+v);else ins(x+(v-mx+y),mx),ins(x-(v-mx+y),mx);
	}
	int p=1;rep(i,2,len)if(s[i].x<s[p].x||s[i].x==s[p].x&&s[i].y<s[p].y)p=i;
	swap(s[1],s[p]);
	sort(s+2,s+len+1,cmp);
//	rep(i,1,len)printf("%d %d\n",s[i].x,s[i].y);
	rep(i,1,len){
		while(top>=2&&Cross(s[i]-sta[top-1],sta[top]-sta[top-1])>=0)top--;
		sta[++top]=s[i];
	}
	sta[top+1]=sta[1];sta[top+2]=sta[2];
//	rep(i,1,top)printf("%d %d\n",sta[i].x,sta[i].y);
	double ans=-1e100;int pp=0;
	rep(i,1,top){
		double R=getlen(sta[i+1]-sta[i])*getlen(sta[i+2]-sta[i])*getlen(sta[i+2]-sta[i+1])/2/Abs(Cross(sta[i+2]-sta[i],sta[i+1]-sta[i]));
		if(R>ans)ans=R,pp=i;
	}
	rep(i,pp,pp+2)printf("%d %d\n",sta[i].x,sta[i].y);
	return 0;
}