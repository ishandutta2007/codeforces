#include<bits/stdc++.h>
using namespace std;
string s;
void read(string &s){
	s="";char ch=getchar();
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
int num[11][11][12],dp[2000004],vis[12][12],ans[12][12];
int main(){
	for (int i=0;i<10;i++)for(int j=0;j<10;j++)for(int k=0;k<12;k++)num[i][j][k]=1e9; 
	for (int i=0;i<10;i++)for(int j=0;j<10;j++)
		for (int k=0;k<20;k++) for (int l=0;l<20;l++) if ((l+k)>0)
			num[i][j][(i*k+j*l)%10]=min(num[i][j][(i*k+j*l)%10],k+l);
	read(s);
	for (int i=0;i<10;i++)for(int j=0;j<10;j++){
		if (vis[j][i]) ans[i][j]=ans[j][i];
		vis[i][j]=1;
		dp[0]=0;
		for (int k=1;k<s.size();k++){
			int need=s[k]-s[k-1];
			dp[k]=1e9;
			dp[k]=min(dp[k],dp[k-1]+num[i][j][(10+need)%10]);
			if (dp[k]==1e9){
				ans[i][j]=-1;
				break;
			}
		}
		if (ans[i][j]!=-1)ans[i][j]=dp[s.size()-1]-s.size()+1;
	}
	for (int i=0;i<10;i++,puts(""))for(int j=0;j<10;j++)printf("%d ",ans[i][j]);
}