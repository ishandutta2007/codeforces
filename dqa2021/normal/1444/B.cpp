    #include<cstdio>
    #include<algorithm>
    #include<cctype>
    using namespace std;
    #define G getchar()
    int read()
    {
    	int x=0; bool flg=false; char ch=G;
    	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
    	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
    	return flg?-x:x;
    }
    #undef G
    typedef long long ll;
    const int mod=998244353;
    int qpow(int x,int y){
    	int res=1;
    	for (;y;y>>=1,x=1LL*x*x%mod)
    		if (y&1) res=1LL*res*x%mod;
    	return res;
    }
    int fac[300010],ifac[300010];
    void init(int x){
    	fac[0]=1; for (int i=1;i<=x;i++) fac[i]=1LL*fac[i-1]*i%mod;
    	ifac[x]=qpow(fac[x],mod-2);
    	for (int i=x;i;i--) ifac[i-1]=1LL*ifac[i]*i%mod;
    }
    int C(int n,int m){return 1LL*fac[n]*ifac[n-m]%mod*ifac[m]%mod;}  //check
     
    int n,w[300010];
    int ans;
    int L,R;
    int main()
    {
    	n=read(); init(n+3);
    	for (int i=1;i<=n+n;i++) w[i]=read();
    	sort(w+1,w+n+n+1);
    	for (int i=1;i<=n;i++) L=(L-w[i]+mod)%mod;
    	for (int i=n+1;i<=n+n;i++) R=(R+w[i])%mod;
    	for (int i=0;i<=n;i++){
    		ans=(ans+1LL*C(n,i)*C(n,n-i))%mod;
    	}
    	ans=1LL*ans*(R+L)%mod;
    	printf("%d\n",ans);
    	return 0;
    }