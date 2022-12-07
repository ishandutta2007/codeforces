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
#define INF 1987654321987654321LL
#define PI 3.14159265358979323
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;
int a[2000], b[2000];
bool chk[4000001];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		chk[a[i]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", b + i);
		chk[b[i]] = 1;
	}
	int c = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			int t = a[i] ^ b[j];
			if (chk[t])c++;
		}
	if (c & 1)puts("Koyomi");
	else puts("Karen");
}