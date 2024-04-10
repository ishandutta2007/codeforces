#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,p[MAXN],f[4][MAXN],ans;
int pre[MAXN],suf[MAXN];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i]);
		if(p[i-1]<p[i]){
			f[0][i]=f[0][i-1]+1;
			f[1][i]=1;
		}else{
			f[0][i]=1;
			f[1][i]=f[1][i-1]+1;
		}
		pre[i]=pre[i-1];
		pre[i]=Max(pre[i],f[0][i]);
		pre[i]=Max(pre[i],f[1][i]);
	}
	per(i,n,1){
		if(p[i+1]<p[i]){
			f[2][i]=f[2][i+1]+1;
			f[3][i]=1;
		}else{
			f[2][i]=1;
			f[3][i]=f[3][i+1]+1;
		}
		suf[i]=suf[i+1];
		suf[i]=Max(suf[i],f[2][i]);
		suf[i]=Max(suf[i],f[3][i]);
	}
	rep(i,2,n-1){
		if(p[i-1]<p[i] && p[i+1]<p[i]){
			//f[0]f[2] 
			int L=i-f[0][i]+1,R=i+f[2][i]-1;
			int Maxn=Max(pre[L],suf[R]);
			if(Maxn>=Max(f[0][i],f[2][i]))continue; 
			if(f[0][i]==f[2][i] && f[0][i]&1)ans++;
		}
	}
	printf("%d",ans);
	return 0;
}