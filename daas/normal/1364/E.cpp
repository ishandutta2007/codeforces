#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,id[1<<11|10],ans[1<<11|10];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) id[i]=i;
	random_shuffle(id+1,id+n+1);
	printf("? %d %d\n",id[1],id[2]);
	fflush(stdout);
	int val=read(),a=1,b=2;
	for(int i=3;i<=n;++i)
	{
		printf("? %d %d\n",id[a],id[i]);
		fflush(stdout);
		int nv=read();
		if(val>nv)
		{
			b=i;
			val=nv;
		}
		else if(val==nv)
		{
			a=i;
			printf("? %d %d\n",id[i],id[b]);
			fflush(stdout);
			val=read();
		}
	}
	int iz,oth;
	srand(time(NULL));
	while(1)
	{
		oth=rand()%n+1;
		while(oth==id[a] || oth==id[b]) oth=rand()%n+1;
		printf("? %d %d\n",id[a],oth);
		fflush(stdout);
		int va=read();
		printf("? %d %d\n",id[b],oth);
		fflush(stdout);
		int vb=read();
		if(va<vb) {iz=id[a];break;}
		else if(vb<va) {iz=id[b];break;}
	}
	for(int i=1;i<=n;++i)
	{
		if(i==iz) continue;
		printf("? %d %d\n",i,iz);
		fflush(stdout);
		ans[i]=read();
	}
	putchar('!');
	for(int i=1;i<=n;++i) printf(" %d",ans[i]);
	putchar('\n');
	return 0;
}