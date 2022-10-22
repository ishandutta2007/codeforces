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
 
const int N=1e6+10,INF=1e9+10;
 
int n,m,g;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
struct Node{
	int x,i;
	bool operator < (const Node __) const {
		return x<__.x;
	}
} A[N],B[N];
int ans[N];
 
 
int main(){
	srand(20040220);
	n=rd();
	g=0;
	rep(i,1,n) g=gcd(g,A[i].x=rd()),A[i].i=i;
	if(g!=1) return puts("NO"),0;
	sort(A+1,A+n+1);
	rep(i,1,n) {
		if(i>2 && A[i].x==A[i-1].x && A[i].x==A[i-2].x) {
			ans[A[i].i]=1;
			continue;
		}
		B[++m]=A[i];
	}
	rep(i,1,m) A[i]=B[i];
	rep(kase,1,5e6/m) {
		g=0;
		int p=1,q;
		//puts("!!");
		while(g!=1) g=gcd(g,A[p++].x);
		q=p,g=0;
		while(p<=m) g=gcd(g,A[p++].x);
		if(g==1) {
			puts("YES");
			rep(i,1,q-1) ans[A[i].i]=1;
			rep(i,q,m) ans[A[i].i]=2;
			rep(i,1,n) printf("%d ",ans[i]);
			return 0;
		}
		random_shuffle(A+1,A+m+1);
	}
	puts("NO");
}