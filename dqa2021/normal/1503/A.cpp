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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n; char s[200010];
char a[200010],b[200010];
bool chk(char *t){
	int top=0;
	rep(i,1,n){
		if (t[i]=='(') ++top;
		else{
			if (!top) return 0;
			--top;
		}
	}
	return top==0;
}
void solve(){
	scanf("%d%s",&n,s+1);
	if (s[1]=='0'||s[n]=='0') return puts("NO"),void();
	int tot0=0,tot1=0;
	rep(i,1,n) tot0+=s[i]=='0',tot1+=s[i]=='1';
	if (tot0&1) return puts("NO"),void();
	vector<char> S,T,P,Q;
	rep(i,1,tot1>>1){
		S.pb('(');
		T.pb('(');
	}
	rep(i,1,tot1>>1){
		S.pb(')');
		T.pb(')');
	}
	rep(i,1,tot0){
		if (i&1){
			P.pb('(');
			Q.pb(')');
		}
		else{
			P.pb(')');
			Q.pb('(');
		}
	}
	reverse(all(S));
	reverse(all(T));
	reverse(all(P));
	reverse(all(Q));
	rep(i,1,n){
		if (s[i]=='1'){
			a[i]=S.back(),b[i]=T.back();
			S.pop_back(); T.pop_back();
		}
		else{
			a[i]=P.back(),b[i]=Q.back();
			P.pop_back(); Q.pop_back();
		}
	}
	a[n+1]=b[n+1]=0;
	if (chk(a)&&chk(b)){
		printf("YES\n%s\n%s\n",a+1,b+1);
	}
	else puts("NO");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}