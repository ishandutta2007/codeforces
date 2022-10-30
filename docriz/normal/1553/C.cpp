#include<bits/stdc++.h>
using namespace std;
int T;
char s[20],tt[20];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int ans=10;
		scanf("%s",s+1);
		for(int t=0;t<2;t++)
		{
			for(int i=1;i<=10;i++)
			{
				if(s[i]!='?')tt[i]=s[i];
				else tt[i]='0'+(t==i%2);
			}
			int cnt[2];
			cnt[0]=cnt[1]=0;
			for(int i=1;i<=10;i++)
			{
				if(tt[i]=='1')cnt[i%2]++;
				if(cnt[!(i%2)]+(11-i)/2<cnt[i%2])ans=min(ans,i);
				if(cnt[i%2]+(10-i)/2<cnt[!(i%2)])ans=min(ans,i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}