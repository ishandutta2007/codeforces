#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,K;

struct C{
	int x,y; double d;
}c[500010];

bool operator<(const C &x,const C &y){
	if (x.x^y.x) return x.x<y.x;
	if (x.y^y.y) return x.y<y.y;
	return x.d<y.d;
}

bool operator==(const C &x,const C &y){
	return x.x==y.x&&x.y==y.y;
}

double F[1000010]; int idtot;
int pos[500010],len[500010],m;

void work(int l,int r,double *G){
	//printf("test work %d %d: ",l,r);
	//rep(i,l,r) printf("%.10lf ",c[i].d); puts("");
	static double S[500010];
	S[l-1]=0;
	rep(i,l,r) S[i]=S[i-1]+c[i].d;
	G[0]=0,G[1]=c[r].d*(K-1);
	int L=l-1,R=r;
	double V=0;
	//rep(i,0,1) printf("G %d = %.10lf  L %d R %d\n",i,G[i],L,R);
	rep(i,2,min(K,r-l+1)){
		double A=0,B=0;
		L++; V+=c[L].d*(L-l)-S[L-1]+(S[r]-S[R-1])-c[L].d*(r-R+1);
		A=(S[L]+S[r]-S[R-1])*(K-i)+V;
		V-=c[L].d*(L-l)-S[L-1]+(S[r]-S[R-1])-c[L].d*(r-R+1); --L;
		
		R--; V+=c[R].d*(L-l+1)-S[L]+(S[r]-S[R])-c[R].d*(r-R);
		B=(S[L]+S[r]-S[R-1])*(K-i)+V;
		V-=c[R].d*(L-l+1)-S[L]+(S[r]-S[R])-c[R].d*(r-R); ++R;
		
		if (A>B) L++,V+=c[L].d*(L-l)-S[L-1]+(S[r]-S[R-1])-c[L].d*(r-R+1),G[i]=A;
		else R--,V+=c[R].d*(L-l+1)-S[L]+(S[r]-S[R])-c[R].d*(r-R),G[i]=B;
		
		//printf("G %d = %.10lf  L %d R %d\n",i,G[i],L,R);
	}
	
}

void solve(int l,int r){
	if (l==r) return;
	int mid=l+r>>1;
	solve(l,mid); solve(mid+1,r);
	
	int al=pos[l],ar=pos[l]+len[l]-1;
	int bl=pos[mid+1],br=pos[mid+1]+len[mid+1]-1;
	int L=min(K,len[l]+len[mid+1]-2);
	
	static double G[1000010]; int top=0;
	G[top]=F[al]+F[bl];
	while (top<L){
		const double A=al<ar?F[al+1]+F[bl]:-1e18;
		const double B=bl<br?F[al]+F[bl+1]:-1e18;
		if (A>B) ++al; else ++bl;
		G[++top]=F[al]+F[bl];
	}
	
	len[l]=L+1;
	rep(i,0,top) F[pos[l]+i]=G[i];
}


void solve(){
	n=read(),K=read();
	rep(i,1,n){
		int x=read(),y=read();
		if (!x&&!y) c[i]=(C){0,0,0};
		else{
			int g=__gcd(abs(x),abs(y));
			double d=sqrt(1LL*x*x+1LL*y*y);
			x/=g,y/=g;
			c[i]=(C){x,y,d};
		}
	}
	sort(c+1,c+n+1);
	for (int l=1,r;l<=n;l=r+1){
		for (r=l;r<n&&c[r]==c[r+1];++r);
		++m; pos[m]=++idtot; len[m]=min(r-l+1,K)+1;
		idtot+=len[m]-1;
		work(l,r,F+pos[m]);
	}
	//rep(i,1,m) printf("block %d: pos %d len %d\n",i,pos[i],pos[i]+len[i]-1);
	solve(1,m);
	printf("%.10lf\n",F[pos[1]+K]);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}