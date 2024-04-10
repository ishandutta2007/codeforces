// Problem: E1. Abnormal Permutation Pairs (easy version)
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.ml/contest/1542/problem/E1
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod;
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};
const int N = 60;
int n;
modint dp[N][N][N*N/2];
//[][][]
modint C[N][N];
modint fac[N];
modint sum[N][N][N*N/2];
signed main() {
	cin>>n>>mod;
	dp[1][1][0]=1;
	for(int i=1;i<50;i++)
		for (int j=1;j<=i;j++)
			for (int k=0;k<=i*(i-1)/2;k++)
				if(dp[i][j][k].x){
					for(int pos=1;pos<=i+1;pos++)
						if(pos==1)
							dp[i+1][i+1][k+i]+=dp[i][j][k];
						else
							dp[i+1][j][k+i+1-pos]+=dp[i][j][k];
				}
	C[0][0]=1;
	for(int i=1;i<N;i++) {
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	fac[0]=1;
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i;
	modint ans=0;
	//sum[i][j][k]=f[i][>=j][<=k]
	for(int i=1;i<=n;i++)
		for(int j=i;j;j--)
			for(int k=0;k<=i*(i-1)/2;k++)
				sum[i][j][k]=dp[i][j][k]+sum[i][j+1][k]+(k==0?0:(sum[i][j][k-1]-sum[i][j+1][k-1]));
	for (int i=1;i<=n;i++) {
		int len=n-i+1;
		modint tmp=0;
		for(int p=1;p<=len;p++)
				for(int A=1;A<=len*(len-1)/2;A++)
					tmp+=dp[len][p][A]*sum[len][p+1][A-1];
		ans+=C[n][len]*tmp*fac[i-1];
	}
	printf("%d", ans);
}