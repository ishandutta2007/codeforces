#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
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
int L,R,cnt,mem[2000][3],pn,st;
int check(int v)
{
	//cout<<"("<<v<<" "<<pn<<") ";
	if(v<=1 || v==pn+1) return v;
	if(v==pn) return 2;
	return v+1;
}
int main()
{
	puts("YES");
	L=read(),R=read();
	if(L!=1)
	{
		st=1;
		mem[++cnt][0]=0;
		mem[cnt][1]=1;
		mem[cnt][2]=L-1;
	}
	int C=R-L+1;
	int LOG=log2(C);
	for(int i=LOG+1;i>=1;--i)
	{
		mem[++cnt][0]=i,mem[cnt][1]=LOG+3,mem[cnt][2]=1;
		for(int j=LOG+1;j>i;--j)
		{
			mem[++cnt][0]=i;
			mem[cnt][1]=j;
			mem[cnt][2]=(1<<(LOG+1-j));
		}
	}
	pn=LOG+2;
	mem[++cnt][0]=1;
	mem[cnt][1]=pn;
	mem[cnt][2]=1;
	int rem=(1<<LOG);
	while(C!=rem)
	{
		int c=log2(C-rem);
		mem[++cnt][0]=pn;
		mem[cnt][1]=LOG+1-c;
		mem[cnt][2]=rem-1;
		rem+=(1<<c);
	}
	printf("%d %d\n",pn+st+1,cnt);
	for(int i=1;i<=cnt;++i) printf("%d %d %d\n",check(mem[i][0])+st,check(mem[i][1])+st,mem[i][2]);
	//cout<<"cao "<<pn<<endl;
	return 0;
}