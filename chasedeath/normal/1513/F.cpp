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

const int N=4e5+10;

int n,m;
int h[N];
int A[N],B[N];
int I[N],J[N];
struct BIT{
	int s[N];
	void Clr(){ memset(s,0,sizeof s); }
	void Add(int p,int x){ while(p<=m) cmax(s[p],x),p+=p&-p; }
	int Que(int p){
		int res=0;
		while(p) cmax(res,s[p]),p-=p&-p;
		return res;
	}
} T;

int main(){
	n=rd();
	ll sum=0;
	int ans=0;
	rep(i,1,n) h[++m]=A[i]=rd();
	rep(i,1,n) h[++m]=B[i]=rd(),sum+=abs(A[i]-B[i]);
	sort(h+1,h+m+1),m=unique(h+1,h+m+1)-h-1;
	rep(i,1,n) {
		I[i]=J[i]=i;
		A[i]=lower_bound(h+1,h+m+1,A[i])-h;
		B[i]=lower_bound(h+1,h+m+1,B[i])-h;
	}
	sort(I+1,I+n+1,[&](int x,int y){ return A[x]<A[y]; });
	sort(J+1,J+n+1,[&](int x,int y){ return B[x]<B[y]; });
	int p=1,ma=0;
	rep(i,1,n) if(A[J[i]]>=B[J[i]]) {
		while(p<=n && A[I[p]]<=B[J[i]]) {
			if(B[I[p]]>=A[I[p]]) {
				T.Add(B[I[p]],B[I[p]]),cmax(ma,B[I[p]]);
			}
			p++;
		}
		if(ma>=A[J[i]]) cmax(ans,2*(h[A[J[i]]]-h[B[J[i]]]));
		cmax(ans,2*(h[T.Que(A[J[i]])]-h[B[J[i]]]));
	}
	p=1,ma=0,swap(I,J),T.Clr();
	rep(i,1,n) if(B[J[i]]>=A[J[i]]) {
		while(p<=n && B[I[p]]<=A[J[i]]) {
			if(B[I[p]]<=A[I[p]]) T.Add(A[I[p]],A[I[p]]),cmax(ma,A[I[p]]);
			p++;
		}
		if(ma>=B[J[i]]) cmax(ans,2*(h[B[J[i]]]-h[A[J[i]]]));
		cmax(ans,2*(h[T.Que(B[J[i]])]-h[A[J[i]]]));
	}
	printf("%lld\n",sum-ans);
}