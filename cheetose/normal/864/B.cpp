#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
char s[201];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	bool chk[26] = { 0 };
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			int temp = 0;
			for (int i = 0; i < 26; i++)
				if (chk[i]) temp++;
			ans = max(ans, temp);
			memset(chk, 0, sizeof(chk));
		}
		else
			chk[s[i] - 'a'] = 1;
	}
	int temp = 0;
	for (int i = 0; i < 26; i++)
		if (chk[i]) temp++;
	ans = max(ans, temp);
	printf("%d", ans);
}