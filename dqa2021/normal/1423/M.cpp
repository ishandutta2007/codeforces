#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<assert.h>
#define pb push_back
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef vector<int> V;
const int INF=1e9+9;
//#define SELFTEST

#ifdef SELFTEST
int mat[5010][5010];
#endif

int n,m;
int ans=INF;
int ask(int x,int y){
	#ifdef SELFTEST
	return mat[x][y];
	#else
	printf("? %d %d\n",x,y); fflush(stdout);
	return read();
	#endif
}
void reduce(int n,V &S,V &T){
	static int A[1000010],B[1000010],Atot,Btot,C[1000010];
	if (T.size()<=S.size()) return;
	Atot=Btot=0;
	for (int x: T) B[++Btot]=x;
	reverse(B+1,B+Btot+1);
	A[++Atot]=B[Btot--]; C[Atot]=ask(S[Atot-1],A[Atot]);
	while (Atot+Btot>n){
		//printf("  Case %d + %d:\n    ",Atot,Btot);
		//for (int i=1;i<=Atot;i++) printf("%d ",A[i]);
		//printf("|| ");
		//for (int i=Btot;i;i--) printf("%d ",B[i]);
		//puts("");
		assert(Atot<=n);
		int t=ask(S[Atot-1],B[Btot]);
		//printf("cur %d nxt %d\n",C[Atot],t);
		if (Atot<n&&C[Atot]<=t){
			A[++Atot]=B[Btot--];
			C[Atot]=ask(S[Atot-1],A[Atot]);
			continue;
		}
		if (Atot==n&&C[Atot]<=t){
			--Btot;
			continue;
		}
		A[Atot]=B[Btot--]; C[Atot]=t;
		if (Atot>1) B[++Btot]=A[Atot--];
	}
	V().swap(T); T.reserve(n);
	for (int i=1;i<=Atot;i++) T.pb(A[i]);
	for (int i=Btot;i;i--) T.pb(B[i]);
}
void solve(int n,vector<int> &S,vector<int> &T){
	//printf("solve %d\n",n);
	reduce(n,S,T);
	//printf("solve %d after reduction: ",n);
	//for (int x: T) printf("%d ",x);
	//puts("");
	if (n==1){
		ans=min(ans,ask(S[0],T[0]));
		return;
	}
	V SS,TT=T,R=T; SS.reserve(n+1>>1);
	for (int i=1;i<=n;i+=2) SS.pb(S[i-1]);
	solve(n+1>>1,SS,TT);
	T.resize(n);
	for (int i=1,j=0;i<=n;i++){
		if (i&1) T[i-1]=TT[i>>1];
		else{
			int l=TT[i-1>>1],r=i==n?INF:TT[i+1>>1];
			int val=INF,pos=-1;
			while (j<R.size()&&R[j]!=l) j++;
			while (j<R.size()&&R[j]!=r){
				//printf("check %d %d\n",S[i-1],R[j]);
				int t=ask(S[i-1],R[j]);
				if (t<val) val=t,pos=R[j];
				j++;
			}
			if (j<R.size()){
				//printf("check %d %d\n",S[i-1],R[j]);
				int t=ask(S[i-1],R[j]);
				if (t<val) val=t,pos=R[j];
			}
			T[i-1]=pos;
			ans=min(ans,val);
			//printf("  checkans %d %d\n",S[i-1],pos);
		}
	}
	//printf("post solve %d\n",n);
	//for (int i=1;i<=n;i++) printf("L %d = %d\n",S[i-1],T[i-1]);
}
int main()
{
	n=read(),m=read();
	#ifdef SELFTEST
	int mn=INF;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			mat[i][j]=read(),mn=min(mn,mat[i][j]);
	#endif
	vector<int> S(n),T(m);
	for (int i=0;i<n;i++) S[i]=i+1;
	for (int i=0;i<m;i++) T[i]=i+1;
	solve(n,S,T);
	#ifdef SELFTEST
	assert(ans==mn);
	puts("AC");
	#else
	printf("! %d\n",ans);
	fflush(stdout);
	#endif
	return 0;
}