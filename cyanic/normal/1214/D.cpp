#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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
 
const int N=1000005,mod=1022332333;
vi f[N],g[N],ban[N];
char s[N];
int n,m;
 
inline void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
 
int main(){
	read(n),read(m);
	rep(i,1,n){
		f[i].resize(m+3);
		g[i].resize(m+3);
		ban[i].resize(m+3);
		scanf("%s",s+1);
		rep(j,1,m)
			ban[i][j]=(s[j]=='#');
	}
	f[1][1]=1;
	rep(i,1,n)rep(j,1,m){
		if(ban[i][j])f[i][j]=0;
		if(f[i][j]){
			if(i<n)add(f[i+1][j],f[i][j]);
			if(j<m)add(f[i][j+1],f[i][j]);
		}
	}
	g[n][m]=1;
	per(i,n,1)per(j,m,1){
		if(ban[i][j])g[i][j]=0;
		if(g[i][j]){
			if(i>1)add(g[i-1][j],g[i][j]);
			if(j>1)add(g[i][j-1],g[i][j]);
		}
	}
	if(f[n][m]==0){
		puts("0");
		return 0;
	}
	rep(i,1,n)rep(j,1,m)
		if(!(i==1&&j==1)&&!(i==n&&j==m))
			if((ll)f[i][j]*g[i][j]%mod==f[n][m]){
				puts("1");
				return 0;
			}
	puts("2");
	return 0;
}