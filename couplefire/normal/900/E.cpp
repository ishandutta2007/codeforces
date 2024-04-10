#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sd(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define MOD 1000000007LL
#define N 100001
 
char str[N];
int num[N];
pii dp1[N];
int dp2[N][2];
 
int main(){
	int n,m;
	sd(n);
	scanf("%s",str);
	sd(m);
	for(int i=n;i>=1;i--)
		str[i]=str[i-1];
	for(int i=1;i<=n;i++){
		num[i]=num[i-1];
		if(str[i]=='?')
			num[i]++;
	}
	for(int i=1;i<=n;i++){
		if(str[i]=='?'){
			dp2[i][0]=1+dp2[i-1][1];
			dp2[i][1]=1+dp2[i-1][0];
		}else if(str[i]=='a')
			dp2[i][0]=1+dp2[i-1][1];
		else
			dp2[i][1]=1+dp2[i-1][0];
	}
	for(int i=m;i<=n;i++){
		dp1[i]=dp1[i-1];
		if(dp2[i][!(m&1)]>=m){
			if(dp1[i-m].F+1>dp1[i].F){
				dp1[i].F=dp1[i-m].F+1;
				dp1[i].S=num[i]-num[i-m]+dp1[i-m].S;
			}else if(dp1[i-m].F+1==dp1[i].F&&num[i]-num[i-m]+dp1[i-m].S<dp1[i].S)
				dp1[i].S=num[i]-num[i-m]+dp1[i-m].S;
		}
	}
	cout<<dp1[n].S<<endl;
}