#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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

int L,R;
int n,m;
int mp[64][64];
void solve(){
	L=read(),R=read();
	n=1;
	while ((1<<n-1)<=R-L+1){
		n++; mp[1][n]=1;
		rep(i,2,n-1) mp[i][n]=1<<i-2;
	}
	
	++n;
	
	if (L==1) L++,mp[1][n]=1;
	per(i,0,25) if (R-L+1>=(1<<i)) mp[i+2][n]=L-1,L+=1<<i;
	
	puts("YES");
	printf("%d ",n);
	rep(i,1,n)
		rep(j,i+1,n)
			m+=mp[i][j]!=0;
	printf("%d\n",m);
	rep(i,1,n)
		rep(j,i+1,n)
			if (mp[i][j])
				printf("%d %d %d\n",i,j,mp[i][j]);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}