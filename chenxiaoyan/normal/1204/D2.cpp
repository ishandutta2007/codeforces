/*








*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=1000000;
int n;
char a[N+5];
int dp[N+2];
int cnt[N+2];
int main(){
	cin>>a+1;
	n=strlen(a+1);
	for(int i=1;i<=n;i++)a[i]=a[i]^48;
	vector<pair<int,int> > rg;
	int nowl=1;
	for(int i=2;i<=n;i++)
		if(a[i-1]&&!a[i])rg.pb(mp(nowl,i-1)),nowl=i;
	rg.pb(mp(nowl,n));
//	for(int i=0;i<rg.size();i++)printf("[%d,%d]\n",rg[i].X,rg[i].Y);
	for(int i=n;i;i--){
		cnt[i]=cnt[i+1]+a[i];
		dp[i]=a[i]?max(cnt[i],dp[i+1]):dp[i+1]+1;
	}
//	for(int i=1;i<=n;i++)printf("dp[%d]=%d\n",i,dp[i]);
	for(int i=0;i<rg.size()-1;i++){
		int l=rg[i].X,r=rg[i].Y;
		int las0;
		for(int j=l;j<=r;j++)if(a[j]){las0=j-1;break;}
		int Delta=max(0,r-l+1+cnt[r+1]-(las0-l+1+dp[r+1]));
		for(int j=l;j<=las0+Delta;j++)cout<<0;
		for(int j=las0+Delta+1;j<=r;j++)cout<<1;
	}
	for(int i=rg.back().X;i<=n;i++)cout<<0;
	return 0;
}