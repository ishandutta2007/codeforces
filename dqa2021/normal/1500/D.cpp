#include<bits/stdc++.h>
#define pb emplace_back
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
typedef pair<short,short> P;
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
//#define G(x) a[x.fi][x.se]

int n,k;
int a[1510][1510];
int ans[1510];

struct C{
	int s;
	int f[12];  // val
	short g[12];  // pos
	
	C merge(const int &ff,const short &gg)const{
		C x(*this);
		int p=-1;
		rep(i,1,x.s) if (x.f[i]==ff){p=i; break;}
		if (!~p&&x.s>k) p=x.s;
		if (!~p) p=++x.s;
		per(i,1,p-1) x.f[i+1]=x.f[i],x.g[i+1]=x.g[i];
		x.f[1]=ff,x.g[1]=gg;
		return x;
	}
	C trans(const int d)const{
		C z(*this);
		rep(i,1,s) z.g[i]+=d;
		return z;
	}
	C operator+(const C &y)const{
		static C z; z.s=0;
		static int vrn[1500*1500+10],tim; ++tim;
		int i=1,j=1;
		while (z.s<=k&&(i<=s||j<=y.s)){
			if (i<=s&&(j>y.s||g[i]<y.g[j])){
				if (vrn[f[i]]^tim){
					vrn[f[i]]=tim;
					z.f[++z.s]=f[i];
					z.g[z.s]=g[i];
				}
				++i;
			}
			else{
				if (vrn[y.f[j]]^tim){
					vrn[y.f[j]]=tim;
					z.f[++z.s]=y.f[j];
					z.g[z.s]=y.g[j];
				}
				++j;
			}
		}
		return z;
	}
	inline int back(){return g[s];}
	
	/*void debugprint(){  // !!!
		rep(i,1,s) printf("%d,%d ",f[i],int(g[i]));
		puts("");
	}*/
}S[1510][1510],T[1510][1510];


void solve(){
	n=read(),k=read();
	rep(i,1,n) rep(j,1,n) a[i][j]=read();
	
	per(i,1,n) per(j,1,n){
		S[i][j]=S[i+1][j].merge(a[i][j],i);
		T[i][j]=T[i][j+1].merge(a[i][j],j);
	}
	rep(_,1,n){
		C W; W.s=0;
		for (int x=n,y=_;x>=1&&y>=1;--x,--y){
			W=W+S[x][y]+T[x][y].trans(-y+x);
			const int z=W.s<=k?n+1:min(n+1,W.back());
			++ans[z-x];
			//printf("ans %d %d: %d\n  ",x,y,z-x);
			//W.debugprint();
		}
	}
	rep(_,1,n-1){
		C W; W.s=0;
		for (int x=_,y=n;x>=1&&y>=1;--x,--y){
			W=W+T[x][y]+S[x][y].trans(-x+y);
			const int z=W.s<=k?n+1:min(n+1,W.back());
			++ans[z-y];
			//printf("ans %d %d: %d\n  ",x,y,z-y);
			//W.debugprint();
		}
	}
	
	per(i,1,n) ans[i]+=ans[i+1];
	rep(i,1,n) printf("%d\n",ans[i]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}