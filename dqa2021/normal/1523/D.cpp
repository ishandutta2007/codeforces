#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
#define pop(x) __builtin_popcount(x)

int n,m,p;
char mp[200010][64];

int S; int T=-1;

int dfn[32],id[64],q;

int c[1<<15];

void check(int x){
//	printf("check %d\n",x);
	q=0;
	rep(i,0,m-1)
		if (mp[x][i]=='1'){
			dfn[q]=i,id[i]=q++;
		}
	memset(c,0,sizeof c);
	rep(i,1,n){
		int msk=0;
		rep(j,0,q-1) if (mp[i][dfn[j]]=='1') msk|=1<<j;
//		printf("test msk %d\n",msk);
		++c[msk];
	}
	rep(i,0,q-1)
		rep(j,0,(1<<q)-1)
			if (j>>i&1)
				c[j^(1<<i)]+=c[j];
	rep(i,0,(1<<q)-1) if (c[i]*2>=n){
//		printf("msk %d: %d\n",i,c[i]);
		if ((!~T||pop(i)>pop(S))){
				
			S=i; T=x;
		} 
	}
}

void solve(){
	n=read(),m=read(),p=read();
	rep(i,1,n) scanf("%s",mp[i]);
	mt19937 rnd(time(0));
	
	
	rep(i,1,20){
		int x=rnd()%n+1;
		check(x);
	}
	int p=0;
	rep(i,0,m-1){
		if (mp[T][i]=='0'){
			putchar('0');
			continue;
		}
		putchar((S>>p&1)^48);
		p++;
	}
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}