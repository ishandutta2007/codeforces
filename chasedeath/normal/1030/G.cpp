#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

const int N=2e6+10,INF=1e9+10,P=1e9+7;

int n,c,ans=1,A[N],B[N],C[N];
vector <int> G[N];
int M[N];

int Add(int x) {
	int f=0;
	for(int i:G[x]) while(x%(M[i]*i)==0) M[i]*=i,f=1;
	return f;
}
void Add2(int x){ for(int i:G[x]) if(x%M[i]==0) C[i]++; }

int Check(int x) {
	for(int i:G[x]) if(x%M[i]==0 && C[i]==1) return 0;
	return 1;
}

int main() {
	rep(i,2,N-1) if(!G[i].size()) {
		M[i]=1;
		for(int j=i;j<N;j+=i) G[j].pb(i);
	}
	n=rd();
	rep(i,1,n) A[rd()]++;
	drep(i,N-1,2) while(A[i]--) {
		if(!Add(i)) {
			Add(i-1),B[i-1]++;
		} else B[i]++;
	}
	rep(i,1,N-1) rep(j,1,B[i]) Add2(i);
	rep(i,2,N-1) if(M[i]) ans=1ll*ans*M[i]%P;
	rep(i,1,N-1) if(B[i] && Check(i)) { c=1; break; }
	printf("%d\n",(ans+c)%P);
}