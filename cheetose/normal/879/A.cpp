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
#include<list>
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323
#define MOD 10007
using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
int n;
int d[1000], s[1000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", s + i, d + i);
	int now = s[0];
	for (int i = 1; i < n; i++)
	{
		if (s[i] > now) now = s[i];
		else
		{
			int temp = now;
			temp -= s[i];
			int tt = temp / d[i] + 1;
			now = tt*d[i] + s[i];
		}
	}
	printf("%d", now);
}