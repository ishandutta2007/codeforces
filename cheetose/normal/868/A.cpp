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
#define INF 987654321
#define PI 3.14159265358979323
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	string a[100];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool chk[2] = { 0 };
	for(int i=0;i<n;i++)
		if (s == a[i])
		{
			puts("YES");
			return 0;
		}
	for (int i = 0; i < n; i++)
	{
		if (s[0] == a[i][1])chk[0] = 1;
		if (s[1] == a[i][0])chk[1] = 1;
	}
	if (chk[0] && chk[1])puts("YES");
	else puts("NO");
}