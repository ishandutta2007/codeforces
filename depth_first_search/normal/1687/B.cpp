#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define M 500 
using namespace std;
int n,m,w[M+5],id[M+5];char s[M+5];
bool cmp(int x,int y) {return w[x]>w[y];}
int main()
{
	int i,j;scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		for(putchar('?'),putchar(' '),j=1;j<=m;++j) putchar(i==j?'1':'0');putchar('\n');
		fflush(stdout),scanf("%d",w+i),id[i]=i,s[i]='1';
	}
	for(putchar('?'),putchar(' '),j=1;j<=m;++j) putchar('1');putchar('\n');
	int lst;fflush(stdout),scanf("%d",&lst);
	int nw,ans=0;for(sort(id+1,id+m+1,cmp),i=1;i^m;++i)
	{
		for(putchar('?'),putchar(' '),s[id[i]]='0',j=1;j<=m;++j) putchar(s[j]);putchar('\n');
		fflush(stdout),scanf("%d",&nw),lst-nw==w[id[i]]&&(ans+=w[id[i]]),lst=nw;
	}return printf("! %d\n",ans+w[id[m]]),0;
}