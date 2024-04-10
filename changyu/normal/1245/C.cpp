#include<cstdio>
const int N=100003,M=1e9+7;
int n,s,k,f[N];char t[N];
signed main()
{
	f[1]=1,f[2]=2;
	for(int i=3;i<N;i++)f[i]=(f[i-1]+f[i-2])%M;
	scanf("%s",t+1);
	s=1;
	k=1;
	for(int i=1;t[i];i++){
	  if(t[i]=='m'||t[i]=='w')return 0*puts("0");
	  if(t[i]==t[i-1])k++;
	  else{
	  	if(i==1)continue;
	  	if(t[i-1]=='n'||t[i-1]=='u')s=1ll*s*f[k]%M;
		k=1;
	  }
	  if(!t[i+1]&&(t[i]=='n'||t[i]=='u'))s=1ll*s*f[k]%M;
	}
	printf("%d",s);
	return 0;
}