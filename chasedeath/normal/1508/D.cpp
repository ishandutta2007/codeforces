#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
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

const int N=3e5+10;

int n,m,O;
int A[N],I[N];
struct Node{
	int x,y;
	Node(){}
	Node(int x,int y):x(x),y(y){}
	Node operator + (const Node _) const { return Node(x+_.x,y+_.y); }
	Node operator - (const Node _) const { return Node(x-_.x,y-_.y); }
	ll operator * (const Node _) const { return 1ll*x*_.x+1ll*y*_.y; }
	db angle() const { return atan2(y,x); }
} P[N];

int C,X[N],Y[N],F[N];
void Swap(int x,int y){ swap(A[x],A[y]),X[++C]=x,Y[C]=y; }
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }
void Union(int x,int y){ F[Find(y)]=Find(x); }

int main(){
	n=rd();
	rep(i,1,n) P[i].x=rd(),P[i].y=rd(),A[i]=rd();
	rep(i,1,n) if(A[i]!=i) O=i;
	if(!O) return puts("0"),0;
	rep(i,1,n) if(i!=O) P[i]=P[i]-P[O],I[++m]=i;
	rep(i,1,n) F[i]=i;
	rep(i,1,n) if(F[i]==i) for(int j=A[i];j!=i;j=A[j]) Union(i,j);
	sort(I+1,I+m+1,[&](int x,int y){ return P[x].angle()<P[y].angle(); });
	rep(i,1,m) if(P[I[i]]*P[I[i%m+1]]>=0 && Find(I[i])!=Find(I[i%m+1])) Union(I[i],I[i%m+1]),Swap(I[i],I[i%m+1]);
	while(A[O]!=O) Swap(A[O],O);
	printf("%d\n",C);
	rep(i,1,C) printf("%d %d\n",X[i],Y[i]);
}