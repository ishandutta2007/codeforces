#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define X first
#define Y second
#define INF 987654231
#define PI 3.14159265358979323
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
int main() {
	int n, a,b,c;
	scanf("%d%d%d%d", &n, &a,&b,&c);
	n--;
	int now = 0;
	int ans = 0;
	while (n--)
	{
		if (now == 0)
		{
			if (a < b)
			{
				ans += a;
				now = 1;
			}
			else
			{
				ans += b;
				now = 2;
			}
		}
		else if (now == 1)
		{
			if (a < c)
			{
				ans += a;
				now = 0;
			}
			else
			{
				ans += c;
				now = 2;
			}
		}
		else if (now == 2)
		{
			if (b < c)
			{
				ans += b;
				now = 0;
			}
			else
			{
				ans += c;
				now = 1;
			}
		}
	}
	printf("%d", ans);
}