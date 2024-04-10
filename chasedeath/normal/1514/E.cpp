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

const int N=2e5+10;

int n;

int Que(int a,int b){
	printf("1 %d %d\n",a,b),fflush(stdout);
	return rd();
}
int P[N];
int L[N],F[N];

int main(){
	rep(_,1,rd()) {
		n=rd();
		rep(i,0,n-1) F[i]=P[i]=i;
		stable_sort(P,P+n,Que);
		rep(i,0,n-1) {
			L[i]=i;
			while(L[i]) {
				printf("2 %d %d ",P[i],L[i]);
				rep(j,0,L[i]-1) printf("%d ",P[j]);
				puts(""),fflush(stdout);
				if(rd()) L[i]=L[L[i]-1];
				else break;
			}
			rep(j,L[i],i) F[P[j]]=i;
		}
		puts("3");
		rep(i,0,n-1) {
			rep(j,0,n-1) putchar((F[i]<=F[j])+'0');
			puts("");
		}
		fflush(stdout);
		if(rd()==-1) break;
	}
}