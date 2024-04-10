#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=3000,M=11,mod=998244353;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return 1LL*a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}
int Power(int a,int k,int p=mod){int res=1;for (;k;k>>=1,smul(a,a,p)) if (k&1) smul(res,a,p);return res;}
int Get_inv(int a,int p=mod){return Power(a,p-2,p);}

int n,m,a[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
}

int ans[N+9];

namespace Sub0{

int dp[2][N+9][(1<<M)+9],now,old;

void Get_dp(){
  dp[0][0][0]=1;now=0;old=1;
  for (int i=1;i<=n;++i){
	now^=1;old^=1;
	for (int j=0;j*m<=n;++j)
	  for (int s=0;s<1<<m;++s) dp[now][j][s]=0;
	for (int j=0;j*m<=n;++j)
	  for (int s=0;s<1<<m;++s){
		if (!dp[old][j][s]) continue;
		int t=dp[old][j][s];
		sadd(dp[now][j][s],t);
		(s|1<<a[i]-1)==(1<<m)-1?sadd(dp[now][j+1][0],t):sadd(dp[now][j][s|1<<a[i]-1],t);
	  }
  }
  for (int i=0;i<=n;++i){
	int sum=0;
	for (int s=0;s<1<<m;++s) sadd(sum,dp[now][i][s]);
	ssub(sum,!i);
	ans[i]=sum;
  }
}

void work(){
  Get_dp();
}

}

namespace Sub1{

int pw[N+9],ipw[N+9];

void Get_pw(){
  pw[0]=ipw[0]=1;
  for (int i=1;i<=n;++i){
	pw[i]=mul(pw[i-1],2);
	ipw[i]=Get_inv(sub(pw[i],1));
  }
}

int f[N+9][N+9],cnt[N+9];

void Get_f(){
  for (int i=1;i<=n;++i){
	for (int j=1;j<=m;++j) cnt[j]=0;
	int now=1,exi=0;
	for (int j=i;j<=n;++j){
	  if (!cnt[a[j]]) ++exi;
	  else if (a[j]==a[i]) smul(now,2);
	    else smul(now,mul(ipw[cnt[a[j]]],sub(pw[cnt[a[j]]+1],1)));
	  ++cnt[a[j]];
	  if (a[i]^a[j]&&exi==m) f[i][j]=mul(now,ipw[cnt[a[j]]]);
	}
  }
}

int dp[N+9][N+9],s[N+9][N+9];

void Get_dp(){
  dp[n+1][0]=s[n+1][0]=1;
  for (int i=n;i>=1;--i){
	int sum=0;
	for (int j=1;j*m<=n-i+1;++j){
	  for (int k=i+m-1;k<=n&&s[k+1][j-1];++k) dp[i][j]=(dp[i][j]+1LL*f[i][k]*s[k+1][j-1])%mod;
	  sadd(sum,dp[i][j]);
	  s[i][j]=add(s[i+1][j],dp[i][j]);
	}
	s[i][0]=add(s[i+1][0],dp[i][0]=sub(pw[n-i],sum));
  }
  ssub(s[1][0],1);
  for (int i=0;i<=n;++i) ans[i]=s[1][i];
}

void work(){
  Get_pw();
  Get_f();
  Get_dp();
}

}

void outo(){
  for (int i=0;i<=n;++i)
	printf("%d ",ans[i]);
  puts("");
}

int main(){
  into();
  m<=M?Sub0::work():Sub1::work();
  outo();
  return 0;
}