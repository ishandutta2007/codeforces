#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
P p[100];
int n, m;
bool ok(int k)
{
	for (int i = 0; i < m; i++)
		if ((p[i].first - 1) / k + 1 != p[i].second)return 0;
	return 1;
}
int main()
{
	vector<int> v1;
	set<int> s;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
	sort(p, p + m);
	for (int i = 1; i <= 100; i++)
		if (ok(i)) v1.push_back(i);
	for (int i = 0; i < v1.size(); i++)
		s.insert((n - 1) / v1[i] + 1);
	if (s.size() != 1)puts("-1");
	else printf("%d", *s.begin());
}