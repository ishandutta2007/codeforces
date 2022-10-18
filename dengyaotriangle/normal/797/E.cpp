#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int ksz=350;

int a[maxn];
int n;
int dp[ksz][maxn]; 

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<ksz;i++){
		for(int j=n;j>=1;j--){
			int nxt=j+i+a[j];
			if(nxt>n)dp[i][j]=1;
			else dp[i][j]=1+dp[i][nxt];
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int p,k;
		cin>>p>>k;
		if(k<ksz){
			cout<<dp[k][p]<<'\n';
		}else{
			int cnt=0;
			while(p<=n){
				p+=a[p]+k;
				cnt++;
			}
			cout<<cnt<<'\n';
		} 
	}
	return 0;
}