#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
P p[200000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
	sort(p, p + n);
	int TV[2] = { -1,-1 };
	for (int i = 0; i < n; i++)
	{
		if (p[i].first <= TV[0] && p[i].first <= TV[1])
		{
			puts("NO");
			return 0;
		}
		else if (p[i].first > TV[0] && p[i].first <= TV[1])
			TV[0] = p[i].second;
		else TV[1] = p[i].second;
	}
	puts("YES");
}