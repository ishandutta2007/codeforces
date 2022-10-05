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

const int N=2005,mod=1e9+7;
int f[N][N],g[N][N],r[N][N],c[N][N];
char s[N][N];
int n,m;

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int main(){
	read(n),read(m);
	if(n==1&&m==1){
		puts("1");
		return 0;
	}
	rep(i,1,n){
		scanf("%s",s[i]+1);
		rep(j,1,m)
			if(s[i][j]=='R'){
				r[i][j]++;
				c[i][j]++;
			}
	}
	per(i,n,1)per(j,m,1){
		r[i][j]+=r[i][j+1];
		c[i][j]+=c[i+1][j];
//		printf("@ %d %d  %d %d\n",i,j,r[i][j],c[i][j]);
	}
	f[1][1]=g[1][1]=1;
	f[2][1]=g[1][2]=mod-1;
	rep(i,1,n)rep(j,1,m){
		add(f[i][j],f[i-1][j]);
		if(f[i][j]){
			int t=r[i][j+1];
			add(g[i][j+1],f[i][j]);
			add(g[i][m-t+1],mod-f[i][j]);
		}
		add(g[i][j],g[i][j-1]);
		if(g[i][j]){
			int t=c[i+1][j];
			add(f[i+1][j],g[i][j]);
			add(f[n-t+1][j],mod-g[i][j]);
		}
//		printf("# %d %d   %d %d\n",i,j,f[i][j],g[i][j]);
	}
	int ans=(f[n][m]+g[n][m])%mod;
	cout<<ans<<endl;
	return 0;
}