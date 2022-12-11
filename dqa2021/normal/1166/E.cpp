#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;

int n,m;
bitset<10010> st[55];
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	{
		int tot,x; scanf("%d",&tot);
		while (tot--) scanf("%d",&x),st[i][x]=true;
	}
	for (int i=1;i<m;i++)
		for (int j=i+1;j<=m;j++)
			if (!((st[i]&st[j]).any()))
				return puts("impossible"),0;
	puts("possible");
	return 0;
}