#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int ch[51],hc[51],co[51],ho[51],ccc[51],hhh[51],ooo[51],cur[51];
bool bj[51],flag;
char ans[60];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("? CH\n");fflush(stdout);
		scanf("%d",ch);
		for(int i=1;i<=*ch;++i)scanf("%d",&ch[i]),bj[ch[i]]=bj[ch[i]+1]=1,ans[ch[i]]='C',ans[ch[i]+1]='H';
		printf("? HC\n");fflush(stdout);
		scanf("%d",hc);
		for(int i=1;i<=*hc;++i)scanf("%d",&hc[i]),bj[hc[i]]=bj[hc[i]+1]=1,ans[hc[i]]='H',ans[hc[i]+1]='C';
		printf("? CO\n");fflush(stdout);
		scanf("%d",co);
		for(int i=1;i<=*co;++i)scanf("%d",&co[i]),bj[co[i]]=bj[co[i]+1]=1,ans[co[i]]='C',ans[co[i]+1]='O';		
		printf("? HO\n");fflush(stdout);
		scanf("%d",ho);
		for(int i=1;i<=*ho;++i)scanf("%d",&ho[i]),bj[ho[i]]=bj[ho[i]+1]=1,ans[ho[i]]='H',ans[ho[i]+1]='O';
		if(!*ch&&!*hc&&!*co&&!*ho)
		{
			printf("? CCC\n");fflush(stdout);
			scanf("%d",ccc);
			for(int i=1;i<=*ccc;++i)scanf("%d",&ccc[i]),bj[ccc[i]]=bj[ccc[i]+1]=bj[ccc[i]+2]=1;
			if(*ccc)for(int i=1;i<=n;++i)ans[i]=bj[i]?'C':'O';
			else
			{
				printf("? HHH\n");fflush(stdout);
				scanf("%d",hhh);
				for(int i=1;i<=*hhh;++i)scanf("%d",&hhh[i]),bj[hhh[i]]=bj[hhh[i]+1]=bj[hhh[i]+2]=1;
				if(*hhh)for(int i=1;i<=n;++i)ans[i]=bj[i]?'H':'O';
				else
				{
					printf("? OOO\n");fflush(stdout);
					scanf("%d",ooo);
					for(int i=1;i<=*ooo;++i)scanf("%d",&ooo[i]),bj[ooo[i]]=bj[ooo[i]+1]=bj[ooo[i]+2]=1;
					if(*ooo==n-2)for(int i=1;i<=n;++i)ans[i]='O';
					else
					{
						if(!*ooo)bj[1]=bj[2]=1;
						printf("? ");
						for(int i=1;i<=n;++i)putchar(bj[i]?'O':'C');putchar('\n');fflush(stdout);
						flag=0;
						scanf("%d",cur);
						for(int i=1;i<=*cur;++i)scanf("%d",&cur[i]),flag|=cur[i]==1;
						if(flag)for(int i=1;i<=n;++i)ans[i]=bj[i]?'O':'C';
						else for(int i=1;i<=n;++i)ans[i]=bj[i]?'O':'H';
					}
				}
			}
		}
		else
		{
			int p;
			for(int i=n;i;--i)if(bj[i]){p=i;break;}
			for(int i=p-1;i;--i)
				if(!bj[i])
				{
					if(ans[i+1]=='O')ans[i]='O';
					else
					{
						putchar('?'),putchar(' ');
						putchar('O');for(int j=i+1;j<=p;++j)putchar(ans[j]);putchar('\n');fflush(stdout);
						flag=0;
						scanf("%d",cur);
						for(int j=1;j<=*cur;++j)scanf("%d",&cur[j]),flag|=cur[j]==i;
						if(flag)ans[i]='O';
						else ans[i]=ans[i+1];
					}
				}
			for(int i=p+1;i<=n;++i)
				if(ans[i-1]!='O')ans[i]=ans[i-1];
				else
				{
					putchar('?'),putchar(' ');
					for(int j=1;j<i;++j)putchar(ans[j]);putchar('O');putchar('\n');fflush(stdout);
					flag=0;
					scanf("%d",cur);
					for(int j=1;j<=*cur;++j)scanf("%d",&cur[j]),flag|=cur[j]==1;
					if(flag)ans[i]='O';
					else
					{
						putchar('?'),putchar(' ');
						for(int j=1;j<=n;++j)putchar(j<i?ans[j]:'C');putchar('\n');fflush(stdout);
						flag=0;
						scanf("%d",cur);
						for(int j=1;j<=*cur;++j)scanf("%d",&cur[j]),flag|=cur[j]==1;
						for(int j=i;j<=n;++j)ans[j]=flag?'C':'H';
					}
				}
		}
		putchar('!'),putchar(' ');
		for(int i=1;i<=n;++i)putchar(ans[i]);putchar('\n');fflush(stdout);
		scanf("%d",&flag);
		memset(bj+1,0,n);
	}
	return 0;
}