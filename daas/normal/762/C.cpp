#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int jump[MAXN][26],pre[MAXN],suf[MAXN],ansa=0,ansb=0x3f3f3f3f;
char s[MAXN],t[MAXN];
int main()
{
	scanf("%s%s",s+1,t+1);
	int lens=strlen(s+1),lent=strlen(t+1);

	for(int i=0;i<26;++i) jump[1][i]=0;
	for(int i=1;i<=lens;++i)
	{
		for(int j=0;j<26;++j) jump[i+1][j]=jump[i][j];
		jump[i+1][s[i]-'a']=i;
	}
	for(int i=lent,cur=jump[lens+1][t[lent]-'a'];i>=1 && cur;--i,cur=jump[cur][t[i]-'a']) suf[i]=cur,ansa=0,ansb=i;

	for(int i=0;i<26;++i) jump[lens][i]=lens+1;
	for(int i=lens;i>=1;--i)
	{
		for(int j=0;j<26;++j) jump[i-1][j]=jump[i][j];
		jump[i-1][s[i]-'a']=i;
	}
	for(int i=1,cur=jump[0][t[1]-'a'];i<=lent && cur!=lens+1;++i,cur=jump[cur][t[i]-'a']) pre[i]=cur;

	for(int i=1;i<=lent && pre[i];++i)
	{
		int l=i+1,r=lent,Z=lent+1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(pre[i]<suf[mid]) Z=mid,r=mid-1;
			else l=mid+1;
		}
		if(ansa+lent-ansb+1<i+lent-Z+1) ansa=i,ansb=Z;
	}
	if(ansa==0 && ansb==0x3f3f3f3f) {puts("-");return 0;}
	for(int i=1;i<=ansa;++i) printf("%c",t[i]);
	for(int i=ansb;i<=lent;++i) printf("%c",t[i]);
	putchar('\n');
	return 0;
}