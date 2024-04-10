#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
struct dot{
	int x,y;dot(int X=0,int Y=0){x=X;y=Y;}
	void read(){scanf("%d%d",&x,&y);}
}A[N],B[N];int n,m;
dot operator - (dot a, dot b) {return dot(a.x-b.x,a.y-b.y);}
ll operator * (dot a, dot b) {return 1LL*a.x*b.y-1LL*a.y*b.x;}
ll dis(dot a) {return 1LL*a.x*a.x+1LL*a.y*a.y;}
bool cmp(dot a, dot b) {ll t=a*b; return t!=0?t>0:dis(a)<dis(b);} 
//lenxydis not x!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
inline ll Abs(ll x) {return x>0?x:-x;}
struct supy{
	int n;dot s[N],sta[N];
inline void solve(dot *A, int &len) {
	int p=1; rep(i,2,n) if (s[i].x<s[p].x||(s[i].x==s[p].x&&s[i].y<s[p].y)) p=i;
	swap(s[1],s[p]); per(i,n,1) s[i]=s[i]-s[1];
	sort(s+1,s+n+1,cmp);
	int top=0; sta[++top]=s[1]; sta[++top]=s[2];
	rep(i,3,n) {
		while (top>1&&(s[i]-sta[top-1])*(sta[top]-sta[top-1])>=0) top--;
		sta[++top]=s[i];
	}
	len=top;rep(i,1,len)A[i]=sta[i];
}
}a,b;
void GG(){puts("NO");exit(0);}
struct node{
	ll a,b,c;
	bool operator < (const node &x)const{return a!=x.a?a<x.a:(b!=x.b?b<x.b:c<x.c);}
};map<node,int>Map;int sz;
int s[N],t[N],nxt[N];
	
int main() {
	read(a.n);read(b.n);
	rep(i,1,a.n)a.s[i].read();
	rep(i,1,b.n)b.s[i].read();
	a.solve(A,n);b.solve(B,m);
	if(n!=m)GG();A[n+1]=A[1];B[n+1]=B[1];A[0]=A[n];B[0]=B[n];
	rep(i,1,n){
		node u;u.a=dis(A[i+1]-A[i]);u.b=dis(A[i]-A[i-1]);u.c=dis(A[i+1]-A[i-1]);
		if(!Map[u])Map[u]=++sz,s[i]=sz;else s[i]=Map[u];
	}
	rep(i,1,n){
		node u;u.a=dis(B[i+1]-B[i]);u.b=dis(B[i]-B[i-1]);u.c=dis(B[i+1]-B[i-1]);
		if(!Map[u])Map[u]=++sz,t[i]=sz;else t[i]=Map[u];
	}
//	printf("%d %d\n",n,m);
//	rep(i,1,n)printf("%d:%d %d\n",i,s[i],t[i]);
	rep(i,1,n)s[i+n]=s[i];m=n;n=n+n;
	for(int i=2,j=0;i<=m;i++){
		while(j&&t[i]!=t[j+1])j=nxt[j];
		if(t[i]==t[j+1])j++;nxt[i]=j;
	}
	for(int i=1,j=0;i<=n;i++){
		while(j&&s[i]!=t[j+1])j=nxt[j];
		if(s[i]==t[j+1])j++;if(j==m){puts("YES");exit(0);}
	}
	puts("NO");return 0;
}