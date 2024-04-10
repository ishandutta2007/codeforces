#include<bits/stdc++.h>
//#define int long long
const int N=505;
using namespace std;

int a[N][N],n,m,ans,S[N][N];
char s[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s+1;
		for(int j=1;j<=m;j++)
			if(s[j]=='B')
				a[i][j]=1;
	}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			a[i][j]=a[i][j]^((S[i+1][j]^S[i+1][j+1]^S[i][j+1])&1);
			if(a[i][j])ans++,S[i][j]=1;
			S[i][j]=S[i][j]^S[i+1][j]^S[i+1][j+1]^S[i][j+1]; 
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]&a[i][m]&a[n][j]&a[n][m]){
				ans--;
				goto end;
			}
	end:cout<<ans;
}