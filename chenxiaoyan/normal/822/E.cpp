#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef unsigned long long ull;
const int N=100000,LOGN=17,S=30;
int n,m,s;
char a[N+10],b[N+10];
const ull hshbs1=131,hshbs2=13331,mod1=1000000007,mod2=1000000009;
ull pw1[N+1],pw2[N+1],Hsha1[N+1],Hsha2[N+1],Hshb1[N+1],Hshb2[N+1];
void hsh_prework(){
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++)
		pw1[i]=pw1[i-1]*hshbs1%mod1,pw2[i]=pw2[i-1]*hshbs2%mod2;
	for(int i=1;i<=n;i++)
		Hsha1[i]=(Hsha1[i-1]*hshbs1+a[i]-'a'+1)%mod1,
		Hsha2[i]=(Hsha2[i-1]*hshbs2+a[i]-'a'+1)%mod2;
	for(int i=1;i<=m;i++)
		Hshb1[i]=(Hshb1[i-1]*hshbs1+b[i]-'a'+1)%mod1,
		Hshb2[i]=(Hshb2[i-1]*hshbs2+b[i]-'a'+1)%mod2;
}
pair<ull,ull> hsha(int l,int r){
	return mp((Hsha1[r]+mod1-Hsha1[l-1]*pw1[r-(l-1)]%mod1)%mod1,
	(Hsha2[r]+mod2-Hsha2[l-1]*pw2[r-(l-1)]%mod2)%mod2);
}
pair<ull,ull> hshb(int l,int r){
	return mp((Hshb1[r]+mod1-Hshb1[l-1]*pw1[r-(l-1)]%mod1)%mod1,
	(Hshb2[r]+mod2-Hshb2[l-1]*pw2[r-(l-1)]%mod2)%mod2);
}
int lcp(int pa,int pb){
	int res=0;
	for(int i=LOGN;~i;i--)
		if(pa+res+(1<<i)-1<=n&&pb+res+(1<<i)-1<=m&&
		hsha(pa,pa+res+(1<<i)-1)==hshb(pb,pb+res+(1<<i)-1))
			res+=1<<i;
	return res;
}
int dp[N+1][S+1];
int main(){
	scanf("%d%s%d%s%d",&n,a+1,&m,b+1,&s);
	hsh_prework();
	for(int i=0;i<n;i++)for(int j=0;j<=s;j++){
		dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		if(j<s){
			int Lcp=lcp(i+1,dp[i][j]+1);
			if(Lcp)dp[i+Lcp][j+1]=max(dp[i+Lcp][j+1],dp[i][j]+Lcp);
		}
	}
	puts(*max_element(dp[n],dp[n]+s+1)==m?"YES":"NO");
	return 0;
}
/*1
9
hloyaygrt
6
loyyrt
3
*/
/*2
9
hloyaygrt
6
loyyrt
2
*/