#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n,m;
bitset<10001> a[100];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k; scanf("%d",&k);
		rep(j,k){ int x; scanf("%d",&x); a[i].set(x); }
	}
	int flag=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if ((a[i]&a[j]).count()==0)flag=0;
	if (flag)puts("possible"); else puts("impossible");
}