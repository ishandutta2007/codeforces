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
//typedef pair<int,int> P;
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

int n,m;
int c[1010][2][2];

bitset<2010> a[2010]; int b[2010];
int z[2010];

/*bool gauss(int n,int m){
	//n=max(n,m);
	rep(i,1,n){
		rep(j,1,m) putchar('0'+a[i][j]);
		printf(" %d\n",b[i]);
	}
	puts("=============");
	rep(i,1,m){
		int p=-1;
		rep(j,i,n) if (a[j][i]){p=j;break;}
		if (!~p) continue;
		if (i^p){
			swap(a[i],a[p]); swap(b[i],b[p]);
		}
		rep(j,i+1,n) if (a[j][i]){
			a[j]^=a[i]; b[j]^=b[i];
		}
	}
	rep(i,1,n){
		rep(j,1,m) putchar('0'+a[i][j]);
		printf(" %d\n",b[i]);
	}
	rep(i,m+1,n) if (a[i].none()&&b[i]) return 0;
	per(i,1,m){
		rep(j,i+1,m) b[i]^=z[j]*a[i][j];
		if (!a[i][i]&&b[i]) return 0;
		z[i]=b[i];
	}
	return 1;
}*/

void gauss_init(int n){
	bitset<2010> &c=a[0];
	int &d=b[0];
	
	/*printf("ins: ");
	rep(i,1,n) putchar('0'+c[i]);
	printf(" %d\n",d);*/
	
	rep(i,1,n) if (c[i]){
		if (a[i][i]) {c^=a[i],d^=b[i]; continue;}
		a[i]=c,b[i]=d; return;
	}
	if (d) puts("NO"),exit(0);
}

void gauss_calc(int n){
	//rep(i,1,n){
	//	rep(j,1,n) putchar('0'+a[i][j]);
	//	printf(" %d\n",b[i]);
	//}
	//puts("=============");
	per(i,1,n){
		rep(j,i+1,n) b[i]^=z[j]*a[i][j];
		z[i]=b[i];
	}
}


int getid(char x){
	if (x=='W') return 0;
	if (x=='R') return 1;
	if (x=='Y') return 2;
	if (x=='B') return 3;
	assert(0);
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) c[i][0][0]=c[i][1][1]=1;
	rep(_,1,m){
		char str[5];
		scanf("%s",str);
		int k=read();
		vector<int> S(k);
		rep(i,0,k-1) S[i]=read();
		if (str[0]=='m'){
			scanf("%s",str);
			int msk=getid(str[0]);
			
			//++top;
			a[0].reset(),b[0]=0;
			rep(i,0,k-1){
				const auto f=c[S[i]];
				//if (f[0][0]) printf("set %d %d\n",0,S[i]);
				//if (f[0][1]) printf("set %d %d\n",0,S[i]+n);
				if (f[0][0]) a[0].flip(S[i]);
				if (f[0][1]) a[0].flip(S[i]+n);
			}
			b[0]=msk&1;
			//printf("b %d = %d\n",0,b[0]);
			gauss_init(n<<1);
			
			//++top;
			a[0].reset(),b[0]=0;
			rep(i,0,k-1){
				const auto f=c[S[i]];
				//if (f[1][0]) printf("set %d %d\n",0,S[i]);
				//if (f[1][1]) printf("set %d %d\n",0,S[i]+n);
				if (f[1][0]) a[0].flip(S[i]);
				if (f[1][1]) a[0].flip(S[i]+n);
			}
			b[0]=msk>>1;
			//printf("b %d = %d\n",0,b[0]);
			gauss_init(n<<1);
		}
		else if (str[0]=='R'&&str[1]=='Y'){
			rep(i,0,k-1) swap(c[S[i]][0],c[S[i]][1]);
		}
		else if (str[0]=='Y'){
			rep(i,0,k-1){
				const auto f=c[S[i]];
				rep(e,0,1) f[0][e]^=f[1][e];
			}
		}
		else{
			rep(i,0,k-1){
				const auto f=c[S[i]];
				rep(e,0,1) f[1][e]^=f[0][e];
			}
		}
	}
	gauss_calc(n<<1);
	//rep(i,1,n+n) printf("x %d = %d\n",i,z[i]);
	puts("YES");
	rep(i,1,n) putchar(".RYB"[z[i]|z[i+n]<<1]);
	puts("");
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}