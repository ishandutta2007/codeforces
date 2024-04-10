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
char s[1010][1010];
int b[1010][1010];
int f[1000010];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
int gethash(int x,int y){
	return (x-1)*m+y;
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x^y) f[y]=x;
}
int getsum(int l,int r,int L,int R){
	return b[r][R]-b[l-1][R]-b[r][L-1]+b[l-1][L-1];
}
int solve(){
	n=read(),m=read();
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m){
		b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(s[i][j]=='#');
	}
	rep(i,1,n) rep(j,1,m){
		if (s[i][j]=='.'&&getsum(i,i,1,j-1)&&getsum(i,i,j+1,m)) return -1;
		if (s[i][j]=='.'&&getsum(1,i-1,j,j)&&getsum(i+1,n,j,j)) return -1;
	}
	int atot=0,btot=0;
	rep(i,1,n) atot+=getsum(i,i,1,m)==0;
	rep(j,1,m) btot+=getsum(1,n,j,j)==0;
	if ((atot==0)^(btot==0)) return -1;
	rep(i,1,n) rep(j,1,m){
		if (s[i][j]=='.') continue;
		if (s[i+1][j]=='#') merge(gethash(i,j),gethash(i+1,j));
		if (s[i][j+1]=='#') merge(gethash(i,j),gethash(i,j+1));
	}
	int tot=0;
	rep(i,1,n) rep(j,1,m) tot+=s[i][j]=='#'&&find(gethash(i,j))==gethash(i,j);
	return tot;
}
int main()
{
	for (int T=1;T--;) printf("%d\n",solve());
	return 0;
}