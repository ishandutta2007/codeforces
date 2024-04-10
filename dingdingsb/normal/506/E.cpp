#pragma GCC optimize(2)
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
const int mod=1e4+7;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=2e2+10,M=3e2+10;
int n,up,len;char s[N];
mint h[N][N][N];bool vis[N][N][N];
mint f[M],g[M][M],cpf[M],cpg[M][M];
mint H(int l,int r,int cnt){
	// [l,r] cnt
	if(cnt<0)return 0;
	if(l==1&&r==n)return !cnt;
	if(vis[l][r][cnt])return h[l][r][cnt];
	vis[l][r][cnt]=1;
	if(l!=1&&s[l-1]!=s[r])h[l][r][cnt]+=H(l-1,r,cnt-1);
	if(r!=n&&s[r+1]!=s[l])h[l][r][cnt]+=H(l,r+1,cnt-1);
	if(l!=1&&r!=n&&s[l-1]==s[r+1])h[l][r][cnt]+=H(l-1,r+1,cnt);
	return h[l][r][cnt];
}
void mulf(){
	static mint tmp[M];memset(tmp,0,sizeof tmp);
	for(int i=1;i<=up;i++)
		for(int j=1;j<=up;j++)
			tmp[j]+=f[i]*g[i][j];
	memcpy(f,tmp,sizeof tmp);
}
void mulg(){
	static mint tmp[M][M];memset(tmp,0,sizeof tmp);
	for(int i=1;i<=up;i++)
		for(int j=i;j<=up;j++)
			for(int k=j;k<=up;k++)
				tmp[i][k]+=g[i][j]*g[j][k];
	memcpy(g,tmp,sizeof tmp);
}
void ksm(int b){
	while(b){
		if(b&1)mulf();
		mulg();b>>=1;
	}
}
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	read(len);len+=n;up=n+(n+1)/2;
	for(int i=0;i<n;i++){
		//
		mint res=0;
		for(int j=1;j<=n;j++){
			res+=H(j,j,i);
			if(s[j]==s[j+1])res+=H(j,j+1,i);
		}
		if(i)g[i][up-(n-i+1)/2]=res;
		else f[n]=res;
	}
	for(int i=2;i<n;i++)g[i-1][i]=1,g[i][i]=24;
	for(int i=n;i<up;i++)g[i][i+1]=1,g[i][i]=25;
	if(n>1)g[1][1]=24,f[1]=1;;g[up][up]=26;
	memcpy(cpf,f,sizeof f);memcpy(cpg,g,sizeof g);
	ksm((len+1)/2);
	if(len%2==0)return writeln(f[up].x),0;
	mint ans=f[up];
	memcpy(f,cpf,sizeof f);memcpy(g,cpg,sizeof g);
	for(int i=0;i<n;i++){
		mint res=0;
		for(int j=1;j<n;j++)if(s[j]==s[j+1])res+=H(j,j+1,i);
		if(i)g[i][up-(n-i+1)/2]=res;
		else f[n]=res;
	}
	g[up][up]=0;
	ksm((len+1)/2);
	writeln((ans-f[up]).x);
	cerr<<"";
}