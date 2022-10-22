#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int M=25;
int cnt[M][M];
char a[N];
int n,m;
int dp[1<<20];
int main() {
	int i,j,k;
	cin>>n>>m;
	cin>>(a+1);
	for(i=1;i<n;i++){
		cnt[a[i]-'a'][a[i+1]-'a']++;
		cnt[a[i+1]-'a'][a[i]-'a']++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(i=1;i<=m;i++){
		for(j=(1<<m)-1;j;j--){
			int cost=0,cc=0;
			for(k=0;k<m;k++) cc+=bool(j&(1<<k));
			if(cc!=i) continue;
			for(k=0;k<m;k++){
				if(!(j&(1<<k))) continue;
				cost=0;
				for(int p=0;p<m;p++){
					if(k==p) continue;
					if(j&(1<<p)) cost+=cnt[k][p]*i;
					else cost-=cnt[k][p]*i;					
				}
				dp[j]=min(dp[j],dp[j-(1<<k)]+cost);
			}
		}
	}
	cout<<dp[(1<<m)-1];
    return 0;
}