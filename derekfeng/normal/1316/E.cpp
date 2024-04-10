#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
struct NUM{
	int a,num[7];
};
bool operator < (const NUM &A,const NUM &B){
    return A.a>B.a;
}
int n,K,miko[130],p;
ll dp[130];
NUM A[100004];
int main(){
	read(n),read(p),read(K);
	for (int i=1;i<=n;i++) read(A[i].a);
	for (int i=1;i<=n;i++) for (int j=0;j<p;j++) read(A[i].num[j]);
	sort (A+1,A+1+n);
	for (int i=1;i<(1<<p);i++) miko[i]=__builtin_popcount(i),dp[i]=-1;
	for (int i=1;i<=n;i++){
		for (int j=(1<<p)-1;j>=0;j--){
			if (i-miko[j]<=K && dp[j]>=0) dp[j]+=A[i].a;
			for (int k=0;k<p;k++) if (((1<<k)&j)>0 && dp[(1<<k)^j]>=0) dp[j]=max(dp[j],dp[j^(1<<k)]+A[i].num[k]);
		}
	}
	write(dp[(1<<p)-1]);
}