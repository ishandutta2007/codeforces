//  228

#include <cstdio>
#define maxn 15
using namespace std;

char a[maxn][5];
int b[maxn], c[maxn], n;

inline bool check(const int* res)
{
	for(int i=0; i<n; i++)
	{
		int b2 = 0, c2 = 0;
		for(int j=0; j<4; j++)
			for(int k=0; k<4; k++)
				if(res[j] == a[i][k] - '0')
				{
					if(k == j) b2 ++;
					else c2 ++;
				}
		if(b2 != b[i] || c2 != c[i])
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s%d%d", a[i], b + i, c + i);
	bool ok = false;
	int ans[4];
	for(int d1=0; d1<10; d1++)
		for(int d2=0; d2<10; d2++) if(d2 != d1)
			for(int d3=0; d3<10; d3++) if(d3 != d2 && d3 != d1)
				for(int d4=0; d4<10; d4++) if(d4 != d3 && d4 != d2 && d4 != d1)
				{
					const int res[] = {d1, d2, d3, d4};
					if(check(res))
					{
						if(ok)
						{
							puts("Need more data");
							return 0;
						}
						ok = true;
						for(int i=0; i<4; i++)
							ans[i] = res[i];
					}
				}
	if(ok)
		for(int i=0; i<4; i++)
			printf("%d", ans[i]);
	else puts("Incorrect data");
	return 0;
}