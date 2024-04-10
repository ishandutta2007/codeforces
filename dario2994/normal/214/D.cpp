#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
typedef long long LL;

LL n;
LL a[10];
LL dp[210][1024];
LL dp0[210][1024];
LL mm=1000000007;
LL binom[210][210];

void binomialize(){
	for(int i=1;i<210;i++){
		binom[i][0]=1;
		binom[i][i]=1;
		for(int j=1;j<i;j++)binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%mm;
	}
}



int main(){
	binomialize();
	cin >> n;
	for(int i=0;i<10;i++)cin >> a[i];
	for(int i=0;i<1024;i++){
		int r=0;
		int q=0;
		for(int s=0;s<10;s++)if((i>>s)%2==1){
			q++;
			r+=a[s];
		}
		if(r==1)dp[1][i]=1;
		if(r==0)dp[1][i]=q;
		if(r==0)dp[0][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<1024;j++){
			for(int s=0;s<10;s++){
				if((j>>s)%2==0)continue;
				
				if(s>0)dp0[i][j]=(dp0[i][j]+dp[i-1][j])%mm;
				dp[i][j]=(dp[i][j]+dp[i-1][j])%mm;
				if(a[s]<=i and a[s]>0){//tocca stare attenti all'inizio
					if(s>0)dp0[i][j]=(dp0[i][j]+binom[i-1][a[s]-1]* dp[i-a[s]][j-(1<<s)])%mm;
					dp[i][j]=(dp[i][j]+binom[i-1][a[s]-1]* dp[i-a[s]][j-(1<<s)])%mm;
				}
			}
		}
	}
	LL res;
	int ss=0;
	for(int i=0;i<10;i++)ss+=a[i];
	if(a[0]>0)res=0;
	else if(ss==0)res=9;
	else if(ss==1)res=1;
	else res=0;
	for(int i=2;i<=n;i++) res=(res+dp0[i][1023])%mm;
	cout << res;
}