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

const int N=5005,M=N*2;
int cur[N][M],r[N][M],f[M],g[M],a[N],sum[N],ans[N];
int n,B,owo;

int main(){
	read(n),read(B);
	rep(i,1,n) read(a[i]),sum[i]=sum[i-1]+a[i];
	memset(f,0xc0,sizeof f);
	f[0]=0,owo=0;
	rep(i,1,n){
		memset(g,0xc0,sizeof g);
		rep(j,0,owo){
			if(f[j]<0) continue;
			int rem=B-f[j]+j;
			int lim=min(a[i]/2,rem);
			int L=(a[i]-lim)/10;
			int R=a[i]/10;
			rep(k,L,R){
				int val=min(min(a[i]/2,rem),a[i]-k*10);
				if(f[j]+val>g[j+k]){
					g[j+k]=f[j]+val;
					cur[i][j+k]=j;
					r[i][j+k]=val;
				}
			}
		}
		memcpy(f,g,sizeof f);
		owo+=a[i]/10;
	}
	int mx=0;
	rep(j,0,owo) if(f[j]>f[mx]) mx=j;
	printf("%d\n",sum[n]-f[mx]);
	for(int i=n,j=mx;i;j=cur[i][j],i--) ans[i]=r[i][j];
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}