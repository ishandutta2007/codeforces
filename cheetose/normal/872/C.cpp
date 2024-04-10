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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
int main() {
	int q;
	scanf("%d", &q);
	while (q--)
	{
		VI v;
		int n;
		scanf("%d", &n);
		if (n == 1 || n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
			puts("-1");
		else
		{
			int ans = 0;
			if (n & 1)
			{
				ans++;
				n -= 9;
			}
			printf("%d\n", ans + n / 4);
		}
	}
}