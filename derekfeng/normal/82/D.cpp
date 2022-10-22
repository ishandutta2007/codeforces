#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int n,dp[1003][1003],a[1003];
int lst[1003][1003],a1[1003][1003],a2[1003][1003];
void output(int x,int ft){
	if (x!=3) output(x-2,lst[x][ft]);
	cout<<a1[x][ft]<<" "<<a2[x][ft]<<"\n";
}
int main(){
	for (int i=0;i<1003;i++) for(int j=0;j<1003;j++) dp[i][j]=1e9+10;
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	dp[1][1]=0;
	if (n==1){
		cout<<a[1]<<"\n"<<1;return 0;
	}
	if (n==2){
		cout<<max(a[1],a[2])<<"\n"<<"1 2"<<"\n";return 0;
	}
	for (int i=3;i<=n;i+=2)
		for (int j=1;j<=i-2;j++){
			if (dp[i][j]>dp[i-2][j]+max(a[i],a[i-1])){
				dp[i][j]=dp[i-2][j]+max(a[i],a[i-1]);
				lst[i][j]=j,a1[i][j]=i-1,a2[i][j]=i;
			}
			if (dp[i][i-1]>dp[i-2][j]+max(a[j],a[i])){
				dp[i][i-1]=dp[i-2][j]+max(a[j],a[i]);
				lst[i][i-1]=j,a1[i][i-1]=j,a2[i][i-1]=i;
			}
			if (dp[i][i]>dp[i-2][j]+max(a[j],a[i-1])){
				dp[i][i]=dp[i-2][j]+max(a[j],a[i-1]);
				lst[i][i]=j,a1[i][i]=j,a2[i][i]=i-1;
			}
		}
	if (n%2==0){
		int ans=1e9+10,cnt;
		for (int i=1;i<=n-1;i++) if (dp[n-1][i]+max(a[i],a[n])<ans){
			ans=dp[n-1][i]+max(a[i],a[n]);
			cnt=i;
		}
		cout<<ans<<"\n";
		output(n-1,cnt);
		cout<<cnt<<" "<<n<<"\n";
	}else{
		int ans=1e9+10,cnt;
		for (int i=1;i<=n;i++) if (dp[n][i]+a[i]<ans){
			ans=dp[n][i]+a[i];
			cnt=i;
		}
		cout<<ans<<"\n";
		output(n,cnt);
		cout<<cnt<<"\n";
	}
}