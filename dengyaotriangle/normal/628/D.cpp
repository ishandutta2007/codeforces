#include<bits/stdc++.h>

using namespace std;

const long long mdn=1000000007;
const int maxn=2006;

int m,z;
string l,r;
long long dp[maxn][maxn][2]; 

//dp[i][j][k]:i/%m==j/k?:

long long d(int i,int j,int k){
	if(i==0) return (int)(j==0); 
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(k==0){
		return dp[i][j][k]=d(i-1,(j*10+z)%m,!k);
	}else{
		long long ans=0;
		for(int dx=0;dx<10;dx++){
			if(dx==z) continue;
			ans=(ans+d(i-1,(j*10+dx)%m,!k))%mdn;
		}
		return dp[i][j][k]=ans;
	}
}
long long f(string x){
	int s=x.size();
	long long ans=0;
	int cd=0;
	for(int i=0;i<s;i++){
		int cr=x[i]-'0';
		int x=(i+1)%2;
		for(int j=((i==0)?1:0);j<cr;j++){
			if(x==0){
				if(j!=z) continue;
			}else{
				if(j==z) continue;
			}
			ans+=d(s-i-1,(cd*10+j)%m,!x);
			ans%=mdn;
		}
		if(x==0&&z!=cr)break;
		if(x==1&&z==cr)break;
		cd=(cd*10+cr)%m;
	}
	return ans;
}

int d(string x){
	int s=x.size();
	long long cd=0;
	for(int i=0;i<s;i++){
		int cr=x[i]-'0';
		int x=(i+1)%2;
		if(x==0&&cr!=z) return 0;
		if(x==1&&cr==z) return 0;
		cd*=10;
		cd+=cr;
		cd%=m;
	}
	return (int)(cd==0);
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>m>>z;
	cin>>l>>r;
	cout<<(f(r)-f(l)+mdn+d(r))%mdn;
	return 0;
}