#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int mod=1e9+7;
const int maxn=600005;
int fac[maxn],facinv[maxn],pw2[maxn],cntg[maxn];
inline int powmod(int a,int b){
	int res=1;
	for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
int n,l1,l2,a1,b1,c1,a2,b2,c2,cc;
char s1[maxn],s2[maxn];
bool same;
inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
inline void prprpr(){
	pw2[0]=1;
	rep(i,1,maxn-5)pw2[i]=1ll*pw2[i-1]*2%mod;
	fac[0]=1;
	rep(i,1,maxn-5)fac[i]=1ll*fac[i-1]*i%mod;
	facinv[maxn-5]=powmod(fac[maxn-5],mod-2);
	per(i,maxn-6,0)facinv[i]=1ll*facinv[i+1]*(i+1)%mod;
	per(i,n,1){
		cntg[i]=1ll*(n/i)*(n/i)%mod;
		for(int j=i+i;j<=n;j+=i)cntg[i]=(cntg[i]-cntg[j]+mod)%mod;
	}
}
inline void add(int &x,int y){
	x=((x+y)>=mod?(x+y-mod):(x+y));
}
int main(){
	scanf("%s",s1);l1=strlen(s1);
	scanf("%s",s2);l2=strlen(s2);
	read(n);
	prprpr();
	if(l1==l2){
		same=1;
		rep(i,0,l1-1)same&=s1[i]=='?'||s2[i]=='?'||s1[i]==s2[i];
	}
	rep(i,0,l1-1){
		a1+=s1[i]=='A';
		b1+=s1[i]=='B';
		c1+=s1[i]=='?';
		cc+=s1[i]=='?'&&s2[i]=='?';
	}
	rep(i,0,l2-1){
		a2+=s2[i]=='A';
		b2+=s2[i]=='B';
		c2+=s2[i]=='?';
	}
	int ans=0;
	for(int k=-l2;k<=l1;k++){
		int val=l1-l2-k;
		int tmp=k-a1+a2+c2;
		if(tmp<0||tmp>c1+c2)continue;
		i64 cnt=C(c1+c2,tmp);
		if(cnt==0)continue;
		if(k==0&&val==0){
			if(same){
				add(ans,1ll*pw2[cc]*(pw2[n+1]+mod-2)%mod*(pw2[n+1]+mod-2)%mod);
				cnt=(cnt-pw2[cc]+mod)%mod;
			}
			rep(i,1,n)add(ans,1ll*cntg[i]*pw2[i]%mod*cnt%mod);
		}
		else if(1ll*k*val<0){
			int x=abs(val),y=abs(k),g=__gcd(x,y);
			x/=g;y/=g;
			add(ans,1ll*cnt*(pw2[n/max(x,y)+1]-2+mod)%mod);
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}