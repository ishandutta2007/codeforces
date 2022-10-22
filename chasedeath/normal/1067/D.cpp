#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10,INF=1e9+10;
const db eps=1e-20;

int n; ll k;
db m;
struct Node{
	db x,y;
	Node(db x=0,db y=0):x(x),y(y){}
	bool operator < (const Node __) const { return x<__.x-eps || (fabs(x-__.x)<eps && y>__.y); }
	Node operator - (const Node _) const { return Node(x-_.x,y-_.y); }
	db operator ^ (const Node _) const { return x*_.y-y*_.x; }
	db operator [] (const db k){ return k*x+y; }
	Node operator * (const Node _) {
		return Node(x*_.x,_.x*y+_.y);
	}
} A[N],S[N],Pow[35];
db Cross(Node a,Node b){ return (b.y-a.y)/(a.x-b.x); }
int T;

int main(){
	n=rd(),k=rd<ll>();
	//ll k_0=k;
	rep(i,1,n) {
		db a=rd(),b=rd(),p; cin>>p;//scanf("%lf",&p);
		cmax(m,p*b),A[i]=Node(1-p,a*p);
	}
	rep(i,1,n) A[i].y=m-A[i].y;
	sort(A+1,A+n+1);
	db miy=1e20;
	rep(i,1,n) {
		if(miy<A[i].y+eps) continue;
		miy=A[i].y;
		//cmin(miy,A[i].y);
		while(T>1 && ((A[i]-S[T])^(S[T-1]-S[T]))<eps) T--;
		S[++T]=A[i];
	}
	db g=0,s=k*m;
	S[0].y=1e40;
	while(k) {
		while(T>1 && S[T-1][g]<=S[T][g]+eps) T--;
		//rep(i,1,T) ;
		//if(T>2 && S[T-2][g]<=S[T][g]) T-=2;
		//db nxt=T>1?Cross(S[T-1],S[T]):1e40;
		Pow[0]=S[T];
		for(int i=1;(1ll<<i)<=k;++i) Pow[i]=Pow[i-1]*Pow[i-1];
		drep(i,34,0) if((1ll<<i)<=k && S[T-1][Pow[i][g]]>=S[T][Pow[i][g]]+eps) k-=1ll<<i,g=Pow[i][g];
		if(k && S[T-1][g]>=S[T][g]+eps) k--,g=Pow[0][g];
	}
	cout<<fixed<<setprecision(10)<<s-g<<endl;
	//printf("%.10lf\n",s-g);
}