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
map<int, int> m;
int main() {
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		if (m[x])m[x]++;
		else m[x] = 1;
	}
	if (m.size() != 2)
	{
		puts("NO");
		return 0;
	}
	map<int, int>::iterator it1,it2;
	it1 = m.begin();
	it2 = it1;
	it2++;
	if (it1->second != it2->second)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d %d", it1->first, it2->first);
}