#include<bits/stdc++.h>
using namespace std;
int T,n;
string s,t;
int f[8][100004],g[100004];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s>>t;s="$"+s,t="$"+t;
		for(int i=0;i<=n;i++)for(int j=0;j<8;j++)f[j][i]=-1e9;
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			s[i]-='0',t[i]-='0';
			for(int j=0;j<8;j++)f[j|(1<<s[i])|(1<<t[i])][i]=max(f[j|(1<<s[i])|(1<<t[i])][i],f[j][i-1]);
			g[i]=-1e9;
			for(int j=0;j<7;j++){
				int k;
				for(k=0;k<3;k++)if(!((1<<k)&j))break;
				g[i]=max(g[i],f[j][i]+k);
			}
			f[0][i]=max(f[0][i],g[i]);
		}
		cout<<g[n]<<"\n";
	}
}