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
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int X; char s[1000010]; int n;
void solve(){
	scanf("%d%s",&X,s+1);
	n=strlen(s+1);
	int L=0,R=n;
	rep(p,1,X){
		add(L,1); iadd(R,1);
		const int c=s[p]-'0';
		for (int d=c-1;d--;){
			rep(i,1,R){
				if (n>=X) break;
				++n; s[n]=s[n-R];
			}
		}
		R=1LL*R*c%mod;
		//s[n+1]=0; puts(s+1);
		//printf("test L %d R %d\n",L,R);
	}
	add(L,R);
	printf("%d  \n   \n",L);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}