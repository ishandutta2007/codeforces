#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(string &s){
	char ch=getchar();s="";
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
string s,t;
int a[19],b[19];
ll dp[2][530000];
int main(){
	for(int i=0;i<2;i++)for(int j=0;j<530000;j++) dp[i][j]=-1;
	read(s),read(t);n=s.size();
	for (int i=0;i<n;i++) a[i]=s[i]-'0',b[i]=t[i]-'0';
	if (t.size()>n){
		sort (a,a+n);
		for (int i=n-1;i>=0;i--) cout<<a[i];
		return 0;
	}
	dp[1][0]=0;
	for (int i=1;i<(1<<n);i++){
		int sz=__builtin_popcount(i);
		for (int j=0;j<n;j++) if ((1<<j)&i){
			if (b[sz-1]==a[j]){
				if (dp[0][i^(1<<j)]!=-1)dp[0][i]=max(dp[0][i],dp[0][i^(1<<j)]*10+a[j]);
				if (dp[1][i^(1<<j)]!=-1)dp[1][i]=max(dp[1][i],dp[1][i^(1<<j)]*10+a[j]);
			}
			if (b[sz-1]<a[j]){
				if (dp[0][i^(1<<j)]!=-1)dp[0][i]=max(dp[0][i],dp[0][i^(1<<j)]*10+a[j]);
			}
			if (b[sz-1]>a[j]){
				if (max(dp[0][i^(1<<j)],dp[1][i^(1<<j)])!=-1)
					dp[0][i]=max(dp[0][i],max(dp[0][i^(1<<j)],dp[1][i^(1<<j)])*10+a[j]);
			}
		}
	}
	write(max(dp[0][(1<<n)-1],dp[1][(1<<n)-1]));
}