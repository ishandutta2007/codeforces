#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=2e6+5;
const int bas[2]={19491001,998244353};
const int mod[2]={1019260817,1000000021};
const int Mod=1e9+7;
int f[N][2],g[N][2],pw[N][2],dp[N][26],n,Q,len,m,K;
char s0[N],s[N],t[N],w[N];

void init(int lim){
	REP(t,2){
		pw[0][t]=1;
		rep(i,1,lim){
			pw[i][t]=(ll)pw[i-1][t]*bas[t]%mod[t];
		}
	}
}

void prepare(){
	rep(i,1,n){
		REP(j,26){
			dp[i][j]=(dp[i-1][j]*2+(t[i]-'a'==j))%Mod;
		}
	}
}

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%Mod){
		if(p&1) res=(ll)res*x%Mod;
	}
	return res;
}

void initHsh(int n,char s[],int f[N][2]){
	rep(i,1,n) REP(t,2){
		f[i][t]=((ll)f[i-1][t]*bas[t]+s[i])%mod[t];
	}
}

pii getHsh(int l,int r,int f[N][2]){
	int res[2];
	REP(t,2){
		res[t]=f[r][t]+mod[t]-(ll)f[l-1][t]*pw[r-l+1][t]%mod[t];
		if(res[t]>=mod[t]) res[t]-=mod[t];
	}
	return mp(res[0],res[1]);
}

void solve(){
	read(K);
	scanf("%s",w+1);
	m=strlen(w+1);
	initHsh(m,w,f);
	len=strlen(s0+1);
	rep(i,1,len) s[i]=s0[i];
	int p=0;
	for(;len<m&&p<K;){
		p++;
		s[len+1]=t[p];
		rep(i,1,len){
			s[len+1+i]=s[i];
		}
		len=len+1+len;
	}
	if(len<m){
		puts("0");
		return;
	}
	initHsh(len,s,g);
	//Case1
	int ans1=0;
	pii aim=getHsh(1,m,f);
	for(int i=1;i+m-1<=len;i++){
		if(getHsh(i,i+m-1,g)==aim) ans1++;
	}
	ans1=(ll)ans1*power(2,K-p)%Mod;
	//Case2
	int val[26],tmp=power(2,K-p)%Mod;
	REP(i,26){
		val[i]=(dp[K][i]+Mod-(ll)tmp*dp[p][i]%Mod)%Mod;
	}
	int ans2=0;
	rep(i,1,m){
		if(getHsh(1,i-1,f)==getHsh(len+1-(i-1),len,g)
		 &&getHsh(i+1,m,f)==getHsh(1,m-i,g)){
			 ans2=(ans2+val[w[i]-'a'])%Mod;
		 }
	}
	printf("%d\n",(ans1+ans2)%Mod);
}

int main(){
	init(N-1);
	read(n),read(Q);
	scanf("%s",s0+1);
	scanf("%s",t+1);
	prepare();
	for(;Q;Q--) solve();
	return 0;
}