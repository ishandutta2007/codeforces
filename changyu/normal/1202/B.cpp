#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
const int N=2e6+3;
char s[N];int g[10][10][10],f[10][10][10][10],tmp,ans;
int main(){
	s[0]='0';
	scanf("%s",s+1);
	for(int i=0;i<10;i++)
	  for(int k=0;k<10;k++)
		for(int l=0;l<10;l++){
		  if(i==0){g[i][k][l]=k==l?0:11;continue;}
		  tmp=k;
		  for(g[i][k][l]++,tmp+=i;tmp%10!=l&&g[i][k][l]<11;g[i][k][l]++,tmp+=i);
		}
	for(int i=0;i<10;i++)
	  for(int j=0;j<10;j++)
		for(int k=0;k<10;k++)
		  for(int l=0;l<10;l++){
		  	f[i][j][k][l]=min(g[i][k][l],g[j][k][l]);
		  	for(int o=0;o<10;o++)
			  f[i][j][k][l]=min(f[i][j][k][l],g[i][k][o]+g[j][o][l]);
		  }
	for(int i=0;i<10;i++){
	  for(int j=0;j<10;j++){
	  	ans=0;
		for(int k=s[1]=='0'?2:1;s[k];k++)
		  if(f[i][j][s[k-1]-48][s[k]-48]==11){ans=-1;break;}
		  else ans+=max(f[i][j][s[k-1]-48][s[k]-48]-1,0);
		printf("%d ",ans);
	  }puts("");
	}
	return 0;
}