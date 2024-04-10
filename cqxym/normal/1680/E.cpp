#include<iostream>
using namespace std;
#define R register int
#define INF 999999
inline int Min(int a,int b,int c){
	b=b<c?b:c;
	return a<b?a:b;
}
char s[200001][2];
int f[200001][3],g[200002][3];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=2;i++){
		for(R j=1;j<=n;j++){
			cin>>s[j][i];
		}
	}
	for(R i=1;i<=n;i++){
		for(R j=0;j!=3;j++){
			f[i][j]=g[i][j]=INF;
		}
		if(s[i][0]=='.'&&s[i][1]=='.'){
			f[i][2]=f[i-1][2];
		}
		for(R j=0;j!=2;j++){
			f[i][j]=Min(f[i-1][j]+1+(s[i][j^1]=='*'),f[i-1][j^1]+2,f[i-1][2]+(s[i][j^1]=='*'));
		}
	}
	if(n==1){
		cout<<Min(f[n][0],f[n][1],f[n][2])<<endl;
		return;
	}
	g[n+1][0]=g[n+1][1]=INF;
	g[n+1][2]=0;
	for(R i=n;i!=0;i--){
		if(s[i][0]=='.'&&s[i][1]=='.'){
			g[i][2]=g[i+1][2];
		}
		for(R j=0;j!=2;j++){
			g[i][j]=Min(g[i+1][j]+1+(s[i][j^1]=='*'),g[i+1][j^1]+2,g[i+1][2]+(s[i][j^1]=='*'));
		}
	}
	int ans=INF;
	for(R i=1;i!=n;i++){
		ans=Min(ans,f[i][2]+g[i+1][0],f[i][2]+g[i+1][1]);
		ans=Min(ans,g[i+1][2]+f[i][0],g[i+1][2]+f[i][1]);
		for(R j=0;j!=2;j++){
			for(R k=0;k!=2;k++){
				int t=f[i][j]+g[i+1][k]+(j==k?1:2);
				if(t<ans){
					ans=t;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	f[0][0]=f[0][1]=INF;
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}