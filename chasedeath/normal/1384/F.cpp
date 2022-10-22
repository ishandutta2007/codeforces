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

const int N=310,INF=1e9+10;

int n,m;
int a[N][N],x[N],y[N];
int b[N][N],c[N];
int vis[N*N];
struct Node{ 
	int i,j,x,y; 
	bool operator < (const Node __) const { return x<__.x || (x==__.x && y<__.y); } 
} A[N*N];
int C;

int main(){
	n=rd(),m=rd();
	rep(i,1,n) rep(j,1,m) a[i][j]=rd(),cmax(x[i],a[i][j]),cmax(y[j],a[i][j]);
	sort(x+1,x+n+1),sort(y+1,y+m+1);
	int p1=1,p2=1;
	x[n+1]=1e9,y[m+1]=1e9;
	while(p1<=n && p2<=m) {
		if(x[p1]==y[p2]) b[p1][p2]=x[p1],p1++,p2++;
		else if(x[p1]<y[p2]) b[p1][p2]=x[p1],p1++;
		else b[p1][p2]=y[p2],p2++;
	}
	rep(i,1,n) vis[x[i]]=1;
	rep(i,1,m) vis[y[i]]=1;
	p1=n,p2=m;
	rep(i,1,n) rep(j,1,m) if(!b[i][j]) A[++C]=(Node){i,j,min(x[i],y[j]),max(x[i],y[j])};
	sort(A+1,A+C+1);
	int p=1;
	rep(i,1,C) {
		while(vis[p]) p++;
		if(p>A[i].x) return puts("-1"),0;
		//cout<<"$"<<A[i].i<<' '<<A[i].j<<endl;
		b[A[i].i][A[i].j]=p;
		vis[p]=1;
	}
	;
	//puts("---");
	rep(i,1,n) x[i]=0;
	rep(i,1,m) y[i]=0;
	rep(i,1,n) rep(j,1,m) cmax(x[i],b[i][j]),cmax(y[j],b[i][j]);
	
	rep(i,1,n) {
		rep(j,1,m) if(x[i]==b[i][j]) {
			//cout<<"$"<<i<<' '<<j<<endl;
			sort(b[i]+1,b[i]+j);
			sort(b[i]+j,b[i]+m+1,greater<int>());
		}
	}
	rep(i,1,m) {
		rep(j,1,n) c[j]=b[j][i];
		rep(j,1,n) if(y[i]==c[j]) {
			//cout<<"$"<<i<<' '<<j<<endl;
			sort(c+1,c+j);
			sort(c+j,c+n+1,greater<int>());
		}
		rep(j,1,n) b[j][i]=c[j];
	}

	rep(i,1,n) x[i]=0;
	rep(i,1,m) y[i]=0;
	rep(i,1,n) rep(j,1,m) cmax(x[i],b[i][j]),cmax(y[j],b[i][j]);
	/*rep(i,1,n) cout<<x[i]<<' ';
	puts("");
	rep(i,1,m) cout<<y[i]<<' ';
	puts("");
	puts("---");*/
	rep(i,1,n) {
		rep(j,1,m) printf("%d ",b[i][j]);
		puts("");
	}
}