#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;

int n,m,k;
char s[500010],t[500010];
int nxt1[500010],nxt2[500010];
int minl[500010],maxr[500010];
int minpos,maxpos;
int main()
{
	minpos=INF,maxpos=-INF;
    scanf("%d%d%d%s%s",&n,&m,&k,s+1,t+1);
    for (int i=2,j;i<=m;i++)
    {
        for (j=nxt1[i-1];j&&t[j+1]!=t[i];j=nxt1[j]);
        if (t[j+1]==t[i]) nxt1[i]=j+1;
        else nxt1[i]=0;
    }
    nxt2[m]=m+1;
    for (int i=m-1,j;i;i--)
    {
        for (j=nxt2[i+1];j!=m+1&&t[j-1]!=t[i];j=nxt2[j]);
        if (t[j-1]==t[i]) nxt2[i]=j-1;
        else nxt2[i]=m+1;
    }
//	for (int i=1;i<=m;i++) printf("%d ",nxt1[i]); puts("");
//	for (int i=1;i<=m;i++) printf("%d ",nxt2[i]); puts("");
    for (int i=0;i<=m+1;i++) maxr[i]=-INF,minl[i]=INF;
    for (int i=1,j=0;i<=n;i++)
    {
        for (;j&&t[j+1]!=s[i];j=nxt1[j]);
        if (t[j+1]==s[i]) j++;
        for (;j&&j>k;j=nxt1[j]);
        if (i>=k) minl[j]=min(minl[j],i-k+1);
        if (j==m)
        {
        	minpos=min(minpos,i),maxpos=max(maxpos,i-m+1);
        	j=nxt1[j];
        }
    }
    if (m<=k)
    {
    	if (minpos!=INF&&max(1,minpos-k+1)+k+k-1<=n){printf("Yes\n%d %d\n",max(1,minpos-k+1),max(1,minpos-k+1)+k);return 0;}
   		if (/*printf("test %d %d\n",maxpos,min(n,maxpos+k-1)),*/maxpos!=-INF&&min(n,maxpos+k-1)-k-k>=0){printf("Yes\n%d %d\n",min(n,maxpos+k-1)-k-k+1,min(n,maxpos+k-1)-k+1);return 0;}
    }
    for (int i=n,j=m+1;i;i--)
    {
        for (;j!=m+1&&t[j-1]!=s[i];j=nxt2[j]);
        if (t[j-1]==s[i]) j--;
        for (;j!=m+1&&m-j+1>k;j=nxt2[j]);
        if (i+k-1<=n) maxr[j]=max(maxr[j],i);
        if (j==1) j=nxt2[j];
    }
    for (int i=m;i;i--) minl[nxt1[i]]=min(minl[nxt1[i]],minl[i]);
    for (int i=1;i<=m;i++) maxr[nxt2[i]]=max(maxr[nxt2[i]],maxr[i]);
//	for (int i=1;i<=m;i++) printf("%d ",minl[i]); puts("");
//	for (int i=1;i<=m;i++) printf("%d ",maxr[i]); puts("");
    for (int i=0;i<=m;i++)
        if (minl[i]!=INF&&maxr[i+1]!=-INF&&minl[i]+k<=maxr[i+1])
        {
            printf("Yes\n%d %d\n",minl[i],maxr[i+1]);
            return 0;
        }
    puts("No");
    return 0;
}