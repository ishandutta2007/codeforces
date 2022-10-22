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
const int N=1e6+10,INF=1e9+10;

int n;
int A[N],B[N],C1,C2;
char s[N];

bool Med;
int main() {
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	rep(_,1,rd()) {
		n=rd();
		rep(i,1,n) s[i]=rd();
		C1=C2=0;
		rep(i,1,n) {
			if(s[i]==0) A[++C1]=rd();
			else B[++C2]=rd();
		}
		sort(A+1,A+C1+1,greater<int>());
		sort(B+1,B+C2+1,greater<int>());
		if(C1<C2) {
			rep(i,1,max(C1,C2)) swap(A[i],B[i]);
			swap(C1,C2);
		}
		//cout<<"#"<<C1<<' '<<C2<<endl;
		ll ans=0;
		{
			ll res=0;
			rep(i,1,C2) res+=A[i]*2ll+B[i]*2ll;
			if(C1==C2) res-=B[C2];
			else rep(i,C2+1,C1) res+=A[i];
			//cout<<res<<endl;
			cmax(ans,res);
		};
		{
			ll res=0;
			rep(i,1,C2) res+=A[i]*2ll+B[i]*2ll;
			res-=A[C2];
			rep(i,C2+1,C1) res+=A[i];
			//cout<<res<<endl;
			cmax(ans,res);
		};
		printf("%lld\n",ans);
	}
}