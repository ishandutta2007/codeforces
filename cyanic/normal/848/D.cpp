#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=55,mod=1e9+7;
int f[N][N],g[N][N],t[N][N],inv[N];
int n,m;

int fix(int x){
	return x>=mod?x-mod:x;
}
int mul(int x,int y){
	return (ll)x*y%mod;
}
void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int main(){
	read(n),read(m);
	inv[1]=1;
	rep(i,2,n+1) inv[i]=mul(mod-mod/i,inv[mod%i]);
	f[0][1]=1;
	rep(i,1,n)rep(j,1,i+1){
		rep(p,0,i-1){
			rep(q,j,p+1) add(g[i][j],mul(f[p][q],f[i-p-1][j]));
			rep(q,j+1,i-p) add(g[i][j],mul(f[p][j],f[i-p-1][q]));
		}
		memset(t,0,sizeof t);
		rep(p,0,n-i)rep(q,0,n+1-j){
			int C=1;
			for(int k=1;p+i*k<=n&&q+i*k<=n+1;k++){
				C=mul(C,mul(g[i][j]+k-1,inv[k]));
				add(t[p+i*k][q+j*k],mul(f[p][q],C));
			}
		}
		rep(p,i,n)rep(q,j,n+1) add(f[p][q],t[p][q]);
	}
	cout<<f[n][m]<<endl;
	return 0;
}