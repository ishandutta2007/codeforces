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
#include<functional>
#define X first
#define Y second
#define INF 1000000000
#define PI 3.14159265358979323
#define MOD 1000000007
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef pair<int, char> P;
char s[100001], pre[128], nex[128];
bool chk[128];
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)
	{
		scanf("%s", s);
		int N = strlen(s);
		chk[s[0]] = 1;
		fup(j,1,N-1,1)
		{
			chk[s[j]] = 1;
			if (pre[s[j]] && pre[s[j]] != s[j - 1])
			{
				puts("NO");
				return 0;
			}
			pre[s[j]] = s[j - 1];
		}
		fdn(j, N - 2, 0, 1)
		{
			chk[s[j]] = 1;
			if (nex[s[j]] && nex[s[j]] != s[j + 1])
			{
				puts("NO");
				return 0;
			}
			nex[s[j]] = s[j + 1];
		}
	}
	vector<char> first,ans;
	fup(i, 'a', 'z', 1)
	{
		if (chk[i])
		{
			int cnt = 0;
			int c = i;
			while (1)
			{
				cnt++;
				if (cnt == 28)
				{
					puts("NO");
					return 0;
				}
				if (!nex[c])break;
				c = nex[c];
			}
		}
	}
	fup(i, 'a', 'z', 1)
		if (chk[i] && !pre[i])first.push_back(i);
	sort(first.begin(), first.end());
	for (char c : first)
	{
		char cc = c;
		while (1)
		{
			ans.push_back(cc);
			if (!nex[cc])break;
			cc = nex[cc];
		}
	}
	for (char c : ans)
		printf("%c", c);
}