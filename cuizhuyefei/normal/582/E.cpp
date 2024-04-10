#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<16|3, mo = 1e9+7;
char s[N];int len,n,all,a[N][6];
inline int Mod(int x){return x<mo?x:x-mo;}
inline void fwt_and(Vi a, Vi b, Vi &c){
	rep(j,0,n-1)rep(i,0,all)a[i]=i>>j&1?a[i]:Mod(a[i]+a[i^(1<<j)]);
	rep(j,0,n-1)rep(i,0,all)b[i]=i>>j&1?b[i]:Mod(b[i]+b[i^(1<<j)]);
	rep(i,0,all)a[i]=1LL*a[i]*b[i]%mo;
	rep(j,0,n-1)rep(i,0,all)a[i]=i>>j&1?a[i]:Mod(a[i]-a[i^(1<<j)]+mo);
	rep(i,0,all)c[i]=Mod(a[i]+c[i]);
}
inline void fwt_or(Vi a, Vi b, Vi &c){
	rep(j,0,n-1)rep(i,0,all)a[i]=i>>j&1?Mod(a[i]+a[i^(1<<j)]):a[i];
	rep(j,0,n-1)rep(i,0,all)b[i]=i>>j&1?Mod(b[i]+b[i^(1<<j)]):b[i];
	rep(i,0,all)a[i]=1LL*a[i]*b[i]%mo;
	rep(j,0,n-1)rep(i,0,all)a[i]=i>>j&1?Mod(a[i]-a[i^(1<<j)]+mo):a[i];
	rep(i,0,all)c[i]=Mod(a[i]+c[i]);
}
Vi solve(int l, int r){
	if(l==r){
		Vi res(all+1,0);
		rep(i,1,4)rep(j,0,1)if(s[l]=='?'||('A'+i-1==s[l]&&j==0||'a'+i-1==s[l]&&j==1)){
			int s=0;rep(k,1,n)s|=(a[k][i]^j)<<k-1;
			res[s]++;
		}
		return res;
	}
	int sum=0;
	rep(mid,l,r){
	if(s[mid]==')')sum--;else if(s[mid]=='(')sum++;
	if(s[mid]==')'&&sum==0){
		Vi a=solve(l+1,mid-1),b=solve(mid+3,r-1),res(all+1,0);
		if(s[mid+1]!='|')fwt_and(a,b,res);
		if(s[mid+1]!='&')fwt_or(a,b,res);
		return res;
	}
	}
	assert(0);
}
int main() {
	scanf("%s",s+1);len=strlen(s+1);
	read(n);rep(i,1,n)rep(j,1,5)read(a[i][j]);all=(1<<n)-1;
	Vi res=solve(1,len);
	int s=0;rep(i,1,n)s|=a[i][5]<<i-1;printf("%d\n",res[s]);
	return 0;
}