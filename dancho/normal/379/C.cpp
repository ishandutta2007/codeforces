#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int a[1<<20], n;
pii p[1<<20];
int b[1<<20];
set<int> us;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		p[i] = make_pair(a[i], i);
	}
	
	sort(p, p + n);
	int lu = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i].first > lu)
		{
			lu = p[i].first;
		}
		b[p[i].second] = lu++;
	}
	
	for (int i = 0; i < n-1; i++)
	{
		printf("%d ", b[i]);
	}
	
	printf("%d\n", b[n-1]);
	return 0;
}