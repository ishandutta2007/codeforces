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
#define forall(x,y) for (const int &y: e[x])

int n; char s[1010];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	bool f=0;
	rep(i,1,n) rep(j,i+1,n)
		if (s[i]=='('&&s[j]==')'){
			f=1; break;}
	if (!f) return puts("0"),void();
	puts("1");
	vector<int> S,T;
	int l=1,r=n;
	while (l<=r){
		while (l<=r&&s[l]==')') l++;
		while (l<=r&&s[r]=='(') r--;
		if (l>r) break;
		S.pb(l),T.pb(r),l++,r--;
	}
	printf("%u\n",int(S.size()+T.size()));
	for (int x: S) printf("%d ",x);
	reverse(all(T));
	for (int x: T) printf("%d ",x);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}