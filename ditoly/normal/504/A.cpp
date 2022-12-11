#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 65536
int r[MN+5],s[MN+5],q[MN+5],qn;
int main()
{
	int n=read(),i,ss=0;
	for(i=0;i<n;++i)ss+=r[i]=read(),s[i]=read();
	printf("%d\n",ss>>1);
	for(i=0;i<n;++i)if(r[i]==1)q[++qn]=i;
	for(i=1;i<=qn;++i)if(r[q[i]]==1)
	{
		printf("%d %d\n",q[i],s[q[i]]);
		if(--r[s[q[i]]]==1)q[++qn]=s[q[i]];
		s[s[q[i]]]^=q[i];
	}
}