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

const int N=4e5+10,P=998244353;

int n1,n2,m,w=1;
int S[N][2],F[N],K[N],D[N];
int Find(int x){
	if(F[x]==x) return F[x];
	int f=F[x]; F[x]=Find(F[x]);
	D[x]^=D[f];
	return F[x];
}

int ans;
void Uni(int x,int y){
	int fx=Find(x),fy=Find(y),d=D[x]^D[y]^1;
	if(fx==fy) return;
	if(d) {
		ans-=S[fx][1],Mod2(ans);
		swap(S[fx][0],S[fx][1]);
		ans+=S[fx][1],Mod1(ans);
		D[fx]=1;
		//cout<<"Rev"<<' '<<fx<<endl;
	}
	F[fx]=fy; 
	rep(i,0,1) S[fy][i]+=S[fx][i],Mod1(S[fy][i]);
}
void Add(){
	int x=rd(),y=rd()+n1;
	w*=2,Mod1(w),S[++m][0]=w,F[m]=m;
	if(K[x]<K[y]) swap(x,y);
	if(!K[x]&&!K[y]) K[x]=K[y]=m;
	else if(!K[y]) Uni(K[x],m),K[x]=0,K[y]=m;
	else Uni(K[x],m),Uni(K[y],m),K[x]=K[y]=0;
}

int A[N],C;

int main(){
	n1=rd(),n2=rd();
	rep(_,1,rd()) Add();
	rep(_,1,rd()) {
		if(rd()==1) Add(),printf("%d\n",ans),fflush(stdout);
		else {
			C=0;
			rep(i,1,m) if(Find(i),D[i]==1) A[++C]=i;
			printf("%d\n",C);
			rep(i,1,C) printf("%d ",A[i]);
			puts(""),fflush(stdout);
		}
	}
}