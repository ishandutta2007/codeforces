#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<map>
using namespace std;
typedef unsigned long long ull;
ull getrand()
{
	ull res=0;
	for (int i=0;i<64;i++)
	{
		res<<=1;
		if (rand()<16384) res|=1;
	}
	return res;
}

int n,m,q;
typedef pair<pair<int,int>,pair<int,int> > P;
map<P,ull> mp;
ull tri[2501][2501];
void update(int x,int y,ull val)
{
	for (int i=x;i<=n;i+=(i&-i))
		for (int j=y;j<=m;j+=(j&-j))
			tri[i][j]^=val;
}
ull query(int x,int y)
{
	ull res=0;
	for (int i=x;i;i-=(i&-i))
		for (int j=y;j;j-=(j&-j))
			res^=tri[i][j];
	return res;
}

int main()
{
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1,opt,a,b,c,d;i<=q;i++)
	{
		scanf("%d%d%d%d%d",&opt,&a,&b,&c,&d);
		if (opt==1)
		{
			ull tmp=getrand();
			mp[(P){(pair<int,int>){a,b},(pair<int,int>){c,d}}]=tmp;
			update(a,b,tmp);
			if (c<n) update(c+1,b,tmp);
			if (d<m) update(a,d+1,tmp);
			if (c<n&&d<m) update(c+1,d+1,tmp);
			continue;
		}
		if (opt==2)
		{
			ull tmp=mp[(P){(pair<int,int>){a,b},(pair<int,int>){c,d}}];
			update(a,b,tmp);
			if (c<n) update(c+1,b,tmp);
			if (d<m) update(a,d+1,tmp);
			if (c<n&&d<m) update(c+1,d+1,tmp);
			continue;
		}
		puts(query(a,b)==query(c,d)?"Yes":"No");
	}
	return 0;
}