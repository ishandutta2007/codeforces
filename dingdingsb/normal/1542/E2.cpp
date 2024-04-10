// Problem: CF1542E2 Abnormal Permutation Pairs (hard version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1542E2
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
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
    modint &operator++(int){return *this+=1;}
};
const int N=600;
int n;
modint pool[3][N*N],*dp[2]={&pool[0][N*N/2],&pool[1][N*N/2]},*pre=&pool[2][N*N/2];
modint lowpow[N];modint ans;
#define ot {for(int j=-range;j<=range;j++)printf("%d ",dp[now][j]);puts("");}
signed main(){
	scanf("%d%d",&n,&mod);
	lowpow[0]=1;
	for(int i=1;i<=n;i++)
		lowpow[i]=lowpow[i-1]*(n-i+1);
	int now=0,lst=1,range=0;dp[now][0]=1;
	for(int i=1;i<n;i++){
		// i
		swap(now,lst);
		memset(pool[now],0,sizeof pool[now]);
		int range=(i+1)*(i+1)/2;
		for(int j=-range;j<=range;j++)
			dp[now][j+1]-=2*dp[lst][j],
			dp[now][j+1-i]+=dp[lst][j],
			dp[now][j+1+i]+=dp[lst][j];
		for(int SJYAKIOI=1;SJYAKIOI<=2;SJYAKIOI++){
			for(int j=range;j>=-range;j--)
				dp[now][j]+=dp[now][j+1];
			for(int j=-range;j<=range;j++)
				dp[now][j]=dp[now][j+1];
		}
		pre[-range-1]=0;
		for(int j=-range;j<=range;j++)
			pre[j]=pre[j-1]+dp[now][j];
		modint tmp=0;
		for(int a=1;a<=i+1;a++)
			for(int b=a+1;b<=i+1;b++)
				tmp+=pre[a-b-1];
		//printf("%d %d\n",i,tmp);
		ans+=lowpow[n-i-1]*tmp;
	}
	printf("%d",ans.x);
}