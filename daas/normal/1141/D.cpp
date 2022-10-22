#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int read()
{
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
int num_l[26][150001],num_r[26][150001],lq,rq,n,l[150001],r[150001],ans[150001][2],maxn;
char s1[150001],s2[150001];
int main()
{
	n=read();
	cin>>s1>>s2;
	for(register int i=0;i<n;++i)
		if(s1[i]=='?')
			l[++lq]=i+1;
		else
		{
			int c=s1[i]-'a';
			num_l[c][++num_l[c][0]]=i+1;
		}
	for(register int i=0;i<n;++i)
		if(s2[i]=='?')
			r[++rq]=i+1;
		else
		{
			int c=s2[i]-'a';
			num_r[c][++num_r[c][0]]=i+1;
		}
	for(register int i=0;i<26;++i)
		while(num_l[i][0] && num_r[i][0])
		{
			ans[++maxn][0]=num_l[i][num_l[i][0]];
			ans[maxn][1]=num_r[i][num_r[i][0]];
			--num_l[i][0];
			--num_r[i][0];
		}
	for(register int i=0;i<26;++i)
		while(num_l[i][0] && rq)
		{
			ans[++maxn][0]=num_l[i][num_l[i][0]];
			ans[maxn][1]=r[rq];
			--rq;
			--num_l[i][0];
		}
	for(register int i=0;i<26;++i)
		while(num_r[i][0] && lq)
		{
			ans[++maxn][0]=l[lq];
			ans[maxn][1]=num_r[i][num_r[i][0]];
			--lq;
			--num_r[i][0];
		}
	while(lq && rq)
	{
		ans[++maxn][0]=l[lq];
		ans[maxn][1]=r[rq];
		--lq;
		--rq;
	}
	printf("%d\n",maxn);
	for(register int i=1;i<=maxn;++i)
		printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}