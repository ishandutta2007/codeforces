#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1005
#define ll long long
int T, n, a[MAXN], ok[MAXN], top;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		top=0;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), ok[i]=0;;
		for(int i=1; i<=n; ++i)
		{
			for(int j=top; j<=n; ++j) if(a[j]==i)
			{
				bool can=1;
				int k;
				for(k=j-1; !ok[k]&&k>top; --k) ok[k]=1, std::swap(a[k], a[k+1]);
				top=k+1;
			}
		}
		for(int i=1; i<=n; ++i) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}