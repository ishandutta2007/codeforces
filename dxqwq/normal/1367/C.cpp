#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[1000003];
int sum[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		memset(sum,0,sizeof(sum)),memset(s,0,sizeof(s));
		scanf("%s",s+1);
		for(register int i=1; i<=n<<1; i++) sum[i]=sum[i-1]+(s[i]=='1');
		int last=-k-1,ans=0;
		for(register int i=1; i<=n; i++)
		{
			if(s[i]=='1') last=i;
			if(i-last>k&&sum[i+k]==sum[i]) ++ans,last=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}