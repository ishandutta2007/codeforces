#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
char a[200020];
int st[200020],tp,pos[200020],cnt[26],sum;
int siz[200020],mx;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%s",a+1);
		n=strlen(a+1);
		for(int i=1;i<=n;++i)a[i]-='a';
		sum=0;
		for(int i=2;i<=n;++i)if(a[i]==a[i-1])++cnt[a[i]],++sum;
		mx=0;
		for(int i=0;i<26;++i)mx=max(mx,cnt[i]),++siz[cnt[i]];
		printf("%d\n",max((sum+1)/2,mx)+1);
		int cur=2;pos[0]=1;
		for(int i=2;i<=n;++i,++cur)
			if(a[i]==a[i-1])
			{
				bool op;
				if(2*mx>=sum)op=tp&&a[i]!=st[tp]&&(cnt[a[i]]==mx||cnt[st[tp]]==mx);
				else op=tp&&a[i]!=st[tp];
			//	printf("%d:%d %d %d %d %d %d\n",i,op,a[i],st[tp],siz[a[i]],siz[st[tp]],mx);
				if(!op)st[++tp]=a[i],pos[tp]=cur;
				else
				{
					printf("%d %d\n",pos[tp],cur-1);
					--siz[cnt[a[i]]],--siz[cnt[st[tp]]];
					--cnt[a[i]],--cnt[st[tp]];
					++siz[cnt[a[i]]],++siz[cnt[st[tp]]];
					if(!siz[mx])--mx;
					cur=pos[tp];--tp;
					sum-=2;
				}
			//	for(int j=1;j<=tp;++j)printf("%d ",st[j]);putchar('\n');
			}
		while(tp)
		{
			printf("%d %d\n",pos[tp-1],pos[tp]-1);
			cur-=pos[tp]-pos[tp-1];--tp;
		}
		printf("%d %d\n",1,cur-1);
		memset(cnt,0,sizeof(cnt));
		memset(siz,0,n<<2);
	}
	return 0;
}