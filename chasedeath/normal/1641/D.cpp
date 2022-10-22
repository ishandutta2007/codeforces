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
const int N=1e5+10,INF=1e9+10;

int n,m;
int a[N][5],id[1<<5][5],W[N],J[N];
struct Node{
	int x,y;
	int operator [] (const int &p) const { return ~id[y][p]?a[x][id[y][p]]:0; }
} A[N*31],B[N*31];
int H[N*5],HC,C,c[N*31];
int I[N][32];
void Add(int i,int k) { rep(j,0,(1<<m)-1) c[I[i][j]]+=k; }
int Que(int i) {
	int res=0;
	rep(j,0,(1<<m)-1) if(__builtin_parity(j)) res-=c[I[i][j]];
	else res+=c[I[i][j]];
	return res;
}

bool Med;
int main() {
	n=rd(),m=rd();
	rep(i,1,n) {
		rep(j,0,m-1) a[i][j]=rd();
		W[i]=rd();
		sort(a[i],a[i]+m);
		int f=1;
		rep(j,1,m-1) if(a[i][j]==a[i][j-1]) f=0;
		if(!f) { i--,iend--,n--; continue; }
		rep(j,0,m-1) H[++HC]=a[i][j];
	}
	rep(i,1,n) J[i]=i;
	sort(J+1,J+n+1,[&](int x,int y){ return W[x]<W[y]; });
	sort(H+1,H+HC+1),HC=unique(H+1,H+HC+1)-H-1;
	rep(i,1,n) rep(j,0,m-1) a[i][j]=lower_bound(H+1,H+HC+1,a[i][j])-H;
	rep(i,1,n) rep(j,1,(1<<m)-1) A[++C]=(Node){i,j};
	rep(S,0,(1<<m)-1) {
		memset(id[S],-1,sizeof id[S]);
		int c=0;
		rep(j,0,m-1) if(S&(1<<j)) id[S][c++]=j;
	}
	rep(i,0,m-1) {
		rep(j,1,C) B[j]=A[j],c[A[j][i]]++;
		rep(j,1,HC) c[j]+=c[j-1];
		drep(j,C,1) A[c[B[j][i]]--]=B[j];
		rep(j,0,HC) c[j]=0;
	}
	/*rep(i,1,C) {
		rep(j,0,m-1) cout<<A[i][j]<<' ';
		puts("");
	}*/
	int c=0;
	rep(i,1,C) {
		if(i==1) c++;
		else rep(j,0,m-1) if(A[i][j]!=A[i-1][j]){ c++; break; }
		I[A[i].x][A[i].y]=c;
	}
	int p=0,ans=INF*2;
	rep(i,2,n) {
		Add(J[i-1],1);
		if(Que(J[i])) {
			p=i-1;
			break;
		}
	}
	//rep(i,1,n) cout<<J[i]<<' '; puts("");
	if(!p) return puts("-1"),0;
	//cout<<"#"<<p<<endl;
	/*rep(i,1,n) {
		rep(j,0,(1<<m)-1) cout<<I[i][j]<<' ';
		puts("");
	}*/
	rep(i,p+1,n) {
		while(p && W[J[i]]+W[J[p]]>=ans) p--;
		if(!p || !Que(J[i])) continue;
		cmin(ans,W[J[i]]+W[J[p]]);
		while(p>1) {
			Add(J[p--],-1);
			if(!Que(J[i])) break;
			cmin(ans,W[J[i]]+W[J[p]]);
		}
	}
	printf("%d\n",ans);
}