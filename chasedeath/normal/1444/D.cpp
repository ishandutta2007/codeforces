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

const int N=1010;

int n,m;
int A[N],B[N];
bitset <N*N/2> dp[N];
int Solve(int *A,int k){
	rep(i,1,n) dp[i].reset();
	dp[0].set(0);
	int s=0;
	rep(i,1,n) s+=A[i];
	if(s&1) return 0;
	if(!k) sort(A+1,A+n+1);
	else sort(A+1,A+n+1,greater<int>());
	s/=2;
	rep(i,1,n) dp[i]=dp[i-1]|(dp[i-1]<<A[i]);
	static int X[N],Y[N],P,Q;
	P=Q=0;
	if(!dp[n][s]) return 0;
	drep(i,n,1) {
		if(s>=A[i] && dp[i-1][s-A[i]]) s-=X[++P]=A[i];
		else Y[++Q]=A[i];
	}
	sort(X+1,X+P+1,greater<int>()),sort(Y+1,Y+Q+1);
	rep(i,1,P) A[i]=X[i];
	rep(i,1,Q) A[i+P]=-Y[i];
	return 1;
}

int Check(){
	static int X[N],Y[N];
	rep(i,1,n) X[i]=X[i-1]+A[i],Y[i]=Y[i-1]+B[i];
	rep(i,0,n-1) rep(j,i+1,n-1) {
		int a=X[i],b=X[i+1];
		if(a>b) swap(a,b);
		int c=Y[j],d=Y[j+1];
		if(c>d) swap(c,d);
		if(a<X[j+1] && X[j+1]<b && c<Y[i] && Y[i]<d) return 0;
	}
	return 1;
}
void Out(int k){
	puts("Yes");
	int x=0,y=0;
	rep(i,1,n) {
		if(!k) {
			printf("%d %d\n",x+=A[i],y);
			printf("%d %d\n",x,y+=B[i]);
		} else {
			printf("%d %d\n",x,y+=A[i]);
			printf("%d %d\n",x+=B[i],y);
		}
	}
}

void Solve(){
	rep(i,1,n=rd()) A[i]=rd();
	rep(i,1,m=rd()) B[i]=rd();
	if(n!=m || !Solve(A,0) || !Solve(B,1)) return puts("No"),void();
	if(Check()) return Out(0);
	swap(A,B);
	if(Check()) return Out(1);
	reverse(A+1,A+n+1);
	rep(i,1,n) A[i]=-A[i];
	if(Check()) return Out(1);
	swap(A,B);
	if(Check()) return Out(0);
	puts("No");
}

int main(){
	rep(_,1,rd()) Solve();
}