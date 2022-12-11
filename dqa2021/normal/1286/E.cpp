#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef __int128 lll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
void print(const lll &x){
	if (x>9) print(x/10);
	putchar((x%10)^48);
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

int Q;

struct C{
	int p,w,s;
}stk[600010]; int top;

int nxt[600010],gnd[600010];

char s[600010];

ull S; __int128 W;

void erase(int x){
	int p=lower_bound(stk+1,stk+top+1,(C){x,0,0},
		[&](const C &x,const C &y){
			return x.p<y.p;
		})-stk;
	assert(p<=top);
	S-=stk[p].w; --stk[p].s;
}

void solve(){
	Q=read();
	const uint lim=(1<<30)-1;
	nxt[0]=-1;
	rep(i,1,Q){
		static char str[2];
		scanf("%s",str);
		s[i]=(str[0]-'a'+W%26)%26+'a';  // ???
		const int w=read()^(W&lim);
		//printf("test c %c w %d\n",s[i],w);
		
		if (i>1){
			int j;
			for (j=nxt[i-1];j&&s[j+1]!=s[i];j=nxt[j]);
			if (s[j+1]==s[i]){
				nxt[i]=j+1;
			}
			if (s[nxt[i-1]+1]!=s[i]) gnd[i]=i;
			else gnd[i]=gnd[nxt[i]];
		}
		//printf("%d: nxt %d gnd %d\n",i,nxt[i],gnd[i]);
		int s=1;
		while (top&&w<stk[top].w) S-=1ULL*stk[top].w*stk[top].s,s+=stk[top--].s;
		stk[++top]=(C){i,w,s}; S+=1ULL*stk[top].w*stk[top].s;
		
		for (int j=gnd[i];j;j=gnd[nxt[j]]){
			for (int k=nxt[j-1];k!=nxt[j]-1;k=nxt[k]) erase(i-k);
		}
		W+=S;
		//S+=stk[1].w;
		print(W); putchar(10);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}