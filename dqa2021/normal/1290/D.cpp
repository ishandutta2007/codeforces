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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])


int n,k,S,m;
bool mrk[1050];

bool ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	char s[2];
	scanf("%s",s);
	return s[0]=='N';
}

void ins(int o){
	//printf("ins %d\n",o);
	int l=o*S+1,r=(o+1)*S;
	rep(i,l,r) if (!mrk[i]&&!ask(i)) mrk[i]=1;
}

void solve(){
	n=read(),k=read();
	if (k==1){
		rep(i,1,n) rep(j,i+1,n){
			puts("R"); fflush(stdout);
			ask(i); if (!ask(j)) mrk[j]=1;
		}
		int z=0;
		rep(i,1,n) z+=!mrk[i];
		printf("! %d\n",z);
		fflush(stdout);
		return;
	}
	S=k>>1;
	m=n/S;
	rep(i,0,n/k-1){
		puts("R"); fflush(stdout);
		ins(i); int p=i;
		rep(j,1,m-1)
			if (j&1) ins(p=(p-j+m)%m);
			else ins(p=(p+j)%m);
	}
	int z=0;
	rep(i,1,n) z+=!mrk[i];
	printf("! %d\n",z);
	fflush(stdout);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}