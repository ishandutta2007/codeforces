#include<bits/stdc++.h>
#define K 400005
using namespace std;
int n,p[21][K<<1],f[1<<21],con[21],mn[21],ans;
char s[K];
bool fl[21][K<<1];
int main(){
	scanf("%d",&n);
	for(int i=1,zzx,T;i<=n;i++){
		scanf("%s",s+1);zzx=strlen(s+1);T=mn[i]=0;
		if(s[1]==')')fl[i][K]=1;
		for(int j=1;j<=zzx;j++){
			if(s[j]==')')T--;
			else T++;
			if(!fl[i][T+K])p[i][T+K]++;
			if(j<zzx&&s[j+1]==')')fl[i][T+K]=1;
			mn[i]=min(mn[i],T);
		}
		con[i]=T;
	}
	memset(f,-1,sizeof(f));
	f[0]=0;
	for(int s=0,now;s<(1<<n);s++)if(f[s]>=0){
		ans=max(ans,f[s]);now=0;
		for(int i=1;i<=n;i++)if(s&(1<<i-1))now+=con[i];
		for(int i=1;i<=n;i++)if(!(s&(1<<i-1))){
			if(now+mn[i]<0)ans=max(ans,f[s]+p[i][K-now]);
			else f[s^(1<<i-1)]=max(f[s^(1<<i-1)],f[s]+p[i][K-now]);
		}
	}
	cout<<ans;
	return 0;
}