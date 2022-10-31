#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int F[N][4],G[N][4];
auto f=F,g=G;

void solve(){
	int n;cin>>n;
	string s[2];cin>>s[0]>>s[1];
	s[0]='0'+s[0],s[1]='0'+s[1];
	for(int i=0;i<=n+1;i++)for(int j=0;j<4;j++)f[i][j]=g[i][j]=1e9;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		if(s[0][i]=='*'&&s[1][i]=='*'){
			f[i][3]=min({f[i-1][0],f[i-1][1]+1,f[i-1][2]+1,f[i-1][3]+2});
			f[i][2]=f[i][1]=f[i][3]+1;
		}
		if(s[0][i]=='.'&&s[1][i]=='*'){
			f[i][2]=min({f[i-1][1]+2,f[i-1][2]+1,f[i-1][0]});
			f[i][1]=f[i][2]+1;
		}
		if(s[0][i]=='*'&&s[1][i]=='.'){
			f[i][1]=min({f[i-1][2]+2,f[i-1][1]+1,f[i-1][0]});
			f[i][2]=f[i][1]+1;
		}
		if(s[0][i]=='.'&&s[1][i]=='.'){
			f[i][1]=min({f[i-1][1]+1,f[i-1][2]+2});
			f[i][2]=min({f[i-1][2]+1,f[i-1][1]+2});
			f[i][0]=f[i-1][0];
		}
	}
	swap(f,g);
	f[0][0]=0;
	reverse(s[0].begin()+1,s[0].end());
	reverse(s[1].begin()+1,s[1].end());
	for(int i=1;i<=n;i++){
		if(s[0][i]=='*'&&s[1][i]=='*'){
			f[i][3]=min({f[i-1][0],f[i-1][1]+1,f[i-1][2]+1,f[i-1][3]+2});
			f[i][2]=f[i][1]=f[i][3]+1;
		}
		if(s[0][i]=='.'&&s[1][i]=='*'){
			f[i][2]=min({f[i-1][1]+2,f[i-1][2]+1,f[i-1][0]});
			f[i][1]=min({f[i-1][2]+2,f[i-1][1]+1,f[i-1][0]})+1;
		}
		if(s[0][i]=='*'&&s[1][i]=='.'){
			f[i][1]=min({f[i-1][2]+2,f[i-1][1]+1,f[i-1][0]});
			f[i][2]=min({f[i-1][1]+2,f[i-1][2]+1,f[i-1][0]})+1;
		}
		if(s[0][i]=='.'&&s[1][i]=='.'){
			f[i][1]=min({f[i-1][1]+1,f[i-1][2]+2});
			f[i][2]=min({f[i-1][2]+1,f[i-1][1]+2});
			f[i][0]=f[i-1][0];
		}
	}
	int res=1e18;
	for(int i=0;i<=n;i++){
		res=min({res,
		f[i][0]+g[n-i][1],
		f[i][0]+g[n-i][2],
		f[i][1]+g[n-i][0],
		f[i][2]+g[n-i][0],
		f[i][1]+g[n-i][1]+1,
		f[i][2]+g[n-i][2]+1,
		f[i][1]+g[n-i][2]+2,
		f[i][2]+g[n-i][1]+2,
		});
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}