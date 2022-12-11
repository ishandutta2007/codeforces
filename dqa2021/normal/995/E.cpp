#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;
typedef long long ll;

int u,v,Mod;
char A[100000][100],B[100];
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
map<int,int> mp;
int main()
{
	srand(time(NULL));  //caution rand
	scanf("%d%d%d",&u,&v,&Mod);
	for (int i=0,x;i<100000;i++)
	{
		x=u;
		for (int j=0;j<100;j++)
		{
			A[i][j]=rand()%3+1;
			if (A[i][j]==1) x=(x+1)%Mod;
			else if (A[i][j]==2) x=(x+Mod-1)%Mod;
			else x=qpow(x,Mod-2);
		}
		mp[x]=i;
	}
	while (true)
	{
		int x=v;
		for (int j=0;j<100;j++)
		{
			B[j]=rand()%3+1;
			if (B[j]==1) x=(x+1)%Mod;
			else if (B[j]==2) x=(x+Mod-1)%Mod;
			else x=qpow(x,Mod-2);
		}
		if (!mp.count(x)) continue;
		int pos=mp[x];
		printf("200\n");
		for (int i=0;i<100;i++) printf("%d ",(int)A[pos][i]);
		for (int i=99;i>=0;i--) printf("%d ",(B[i]==3?3:(B[i]==2?1:2))); putchar('\n');
		return 0;
	}
}