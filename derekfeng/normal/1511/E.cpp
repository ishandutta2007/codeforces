#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,cnt,ans;
int f[300004][2],p[300004],pw[300004];
vector<vector<char> >v;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f[0][0]=1,pw[0]=1;
	for(int i=1;i<=n*m;i++){
		pw[i]=(pw[i-1]+pw[i-1])%MOD;
		f[i][1]=f[i-1][0];
		f[i][0]=((f[i-1][0]+f[i-1][1])%MOD+f[i-1][1])%MOD;
		p[i]=((p[i-1]+p[i-1])%MOD+f[i-1][1])%MOD;
	}
	v.resize(n+1);
	for(int i=1;i<=n;i++){
		v[i].resize(m+1);
		for(int j=1;j<=m;j++)cin>>v[i][j],cnt+=(v[i][j]=='o');
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(v[i][j]!='*'){
		if(j==1||v[i][j-1]=='*'){
			int k=j+1;
			while(k<=m&&v[i][k]!='*')k++;
			(ans+=(long long)p[k-j]*pw[cnt-(k-j)]%MOD)%=MOD;
		}
		if(i==1||v[i-1][j]=='*'){
			int k=i+1;
			while(k<=n&&v[k][j]!='*')k++;
			(ans+=(long long)p[k-i]*pw[cnt-(k-i)]%MOD)%=MOD;
		}
	}
	cout<<ans;
}