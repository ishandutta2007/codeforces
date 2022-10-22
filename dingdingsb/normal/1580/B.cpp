#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=102;
int n,m,k,p;
int c[N][N],f[N][N][N];
int dfs(int i,int j,int k){
	//i  j  k  m  
	if(f[i][j][k]!=-1)return f[i][j][k];
	if(2*k>i+1||i<k)return 0;
	if(j>m&&k>0)return 0;
	if(j==m&&k>1)return 0;
	if(i==0)return k==0;
	int lim=k;if(j==m)lim--;
	int &res=f[i][j][k];res=0;
	for(int a=0;a<i;a++)//
		for(int b=0;b<=lim;b++)
			res=(res+1ll*c[i-1][a]*dfs(a,j+1,b)%p*dfs(i-1-a,j+1,lim-b))%p;
	//printf("%d %d %d %d\n",i,j,k,res);
	return res;
}
signed main(){
	memset(f,-1,sizeof f);
	read(n,m,k,p);
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	}
	write(dfs(n,1,k));
}