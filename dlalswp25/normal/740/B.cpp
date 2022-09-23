#include <stdio.h>
#include <vector>

using namespace std;

vector<int> s;
int a[105];

int main()
{
	int n, m;	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)	scanf("%d", &a[i]);
	for(int i = 0; i < m; i++)
	{
		int l, r;	scanf("%d %d", &l, &r);
		l--;	r--;
		int sum = 0;
		for(int j = l; j <= r; j++)	sum += a[j];
		s.push_back(sum);
	}
	int ans = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] > 0)	ans += s[i];
	}
	printf("%d", ans);
	return 0;
}