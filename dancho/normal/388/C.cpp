#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int l, s[1024];

int sf, ss;
vector<int> r;

int main()
{
	scanf("%d", &n);
	sf = ss = 0;
	r.clear();
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l);
		for (int j = 0; j < l; ++j)
		{
			scanf("%d", &s[j]);
		}
		int b = 0, e = l-1;
		while (b < e)
		{
			sf += s[b++];
			ss += s[e--];
		}
		if (b == e)
		{
			r.push_back(s[b]);
		}
	}

	sort(r.begin(), r.end());
	int j = 0;
	for (int i = (int) r.size()-1; i >= 0; --i)
	{
		if (j&1)
			ss += r[i];
		else
			sf += r[i];
		++j;
	}
	printf("%d %d\n", sf, ss);
	return 0;
}