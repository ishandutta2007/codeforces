#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
template<const int mod>
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
const int mod1=998244353;
const int mod2=1e9+7;
const int mod3=1e9+9;
struct Hash{
	mint<mod1>h1;mint<mod2>h2;mint<mod3>h3;
	Hash(char c=0){h1=c,h2=c,h3=c;}
	Hash(mint<mod1>h1,mint<mod2>h2,mint<mod3>h3):h1(h1),h2(h2),h3(h3){}
	Hash operator+(Hash a){return Hash(h1+a.h1,h2+a.h2,h3+a.h3);}
	Hash operator-(Hash a){return Hash(h1-a.h1,h2-a.h2,h3-a.h3);}
	Hash operator*(Hash a){return Hash(h1*a.h1,h2*a.h2,h3*a.h3);}
	bool operator==(Hash a){return h1.x==a.h1.x&&h2.x==a.h2.x&&h3.x==a.h3.x;}
};
const Hash base(117,19491001,223);
const int N=2e3+10;
typedef mint<1000000007> mit;
int n,m;char s[2][N],t[N];
Hash pw[N],h[2][N],a[N],b[N];
mit ans,dp[2][N][N];
Hash Gets(int i,int l,int r){return h[i][r]-h[i][l-1]*pw[r-l+1];}
Hash Gett(int l,int r){
	if(l<=r)return a[r]-a[l-1]*pw[r-l+1];
	else return b[r]-b[l+1]*pw[l-r+1];
}
bool F(int i,int j,int k){
	if(k>2*j||k>m)return 0;
	if(!k)return 1;
	return Gets(i,j-k/2+1,j)==Gett(k/2+1,k)&&Gets(i^1,j-k/2+1,j)==Gett(k/2,1);
}
bool G(int i,int j,int k){
	if(k>2*(n-j+1)||k>m)return 0;
	if(!k)return 0;
	return Gets(i,j,j+k/2-1)==Gett(m-k+1,m-k/2)&&Gets(i^1,j,j+k/2-1)==Gett(m,m-k/2+1);
}
void calc(){
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)h[i][j]=h[i][j-1]*base+s[i][j];
	for(int i=1;i<=m;i++)a[i]=a[i-1]*base+t[i];
	for(int i=m;i>=1;i--)b[i]=b[i+1]*base+t[i];
	G(0,2,2);
	memset(dp,0,sizeof dp);
	if(m%2==0)for(int i=0;i<2;i++)for(int j=1;j<=n;j++)if(F(i,j,m))ans+=1;
	for(int i=0;i<=n;i++)dp[0][i][0]=dp[1][i][0]=1;
	for(int i=1;i<=n;i++){
		if(s[0][i]==t[m])ans+=dp[0][i-1][m-1];
		if(s[1][i]==t[m])ans+=dp[1][i-1][m-1];
		for(int j=0;j<2;j++)for(int k=0;k<m;k++){
			if(s[j][i]==t[k+1])
				dp[j][i][k+1]+=dp[j][i-1][k];
			if(s[j][i]==t[k+1]&&s[j^1][i]==t[k+2])
				dp[j^1][i][k+2]+=dp[j][i-1][k];
		}
		for(int j=0;j<2;j++)for(int k=4;k<m;k+=2)if(F(j,i,k))
			dp[j][i][k]+=1;
		for(int j=0;j<2;j++)for(int k=2;k<m;k++)if(G(j,i+1,k))
			ans+=dp[j][i][m-k];
	}
}
signed main(){
	pw[0]=Hash(1,1,1);for(int i=1;i<N;i++)pw[i]=pw[i-1]*base;
	scanf("%s",s[0]+1);scanf("%s",s[1]+1);scanf("%s",t+1);
	n=strlen(s[0]+1);m=strlen(t+1);
	if(m==1){for(int i=0;i<2;i++)for(int j=1;j<=n;j++)if(s[i][j]==t[1])ans+=1;}
	else if(m==2){
		for(int i=0;i<2;i++)for(int j=1;j<n;j++)if(s[i][j]==t[1]&&s[i][j+1]==t[2])ans+=1;
		for(int i=0;i<2;i++)for(int j=1;j<n;j++)if(s[i][j]==t[2]&&s[i][j+1]==t[1])ans+=1;
		for(int j=1;j<=n;j++)if(s[0][j]==t[1]&&s[1][j]==t[2])ans+=1;
		for(int j=1;j<=n;j++)if(s[0][j]==t[2]&&s[1][j]==t[1])ans+=1;
	}else{
		calc();
		reverse(s[0]+1,s[0]+n+1);
		reverse(s[1]+1,s[1]+n+1);
		calc();
	}
	writeln(ans.x);
	cerr<<"";
}