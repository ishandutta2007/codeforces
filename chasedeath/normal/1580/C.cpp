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

bool Mbe;
const int N=2e5+10,L=sqrt(N/1.3),M=L+10,INF=1e9+10;
//const int N=2e5+10,L=3,M=L+10,INF=1e9+10;

int n,m;
int X[N],Y[N],lst[N];
int S[N],T[M][M],Q[M];
void Add(int x,int y,int k,int t,int i) {
	int l=x+y;
	if(l<=L) {
		int a=(t+x)%l,b=(t+x+y)%l;
		while(a!=b) T[l][a]+=k,a=a==l-1?0:a+1;
	} else {
		int a=t+x;
		while(a+y<=i) a+=l;
		if(a<=m) {
			S[max(a,i)]+=k;
			if(a+y<=m) {
				S[a+y]-=k;
				if(l<=m) {
					while((a+=l)<=m) {
						S[a]+=k;
						a+y<=m && (S[a+y]-=k);
					}
				}
			}
		}
	}
}

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd(),m=rd();
	rep(i,1,n) X[i]=rd(),Y[i]=rd();
	rep(i,1,m) {
		S[i]+=S[i-1];
		int op=rd(),x=rd();
		if(op==1) Add(X[x],Y[x],1,i,i),lst[x]=i;
		else Add(X[x],Y[x],-1,lst[x],i);
		int res=S[i];
		rep(j,1,L) {
			Q[j]=Q[j]==j-1?0:(Q[j]+1);
			res+=T[j][Q[j]];
		}
		printf("%d\n",res);
	}
}