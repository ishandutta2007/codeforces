#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int s = 1000000;

vector<int> sol;
int n;
bool us[1<<20];

int main()
{
	memset(us, 0, sizeof(us));
	scanf("%d", &n);
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		us[k] = 1;
	}

	for (int i = 0; i <= s; i++)
	{
		if (us[i] && us[s + 1 - i])
		{
			++l;
		}
		else if (us[i])
		{
			sol.push_back(s + 1 - i);
		}
	}

	l /= 2;
	for (int i = 1; i <= s && l; ++i)
	{
		if (!us[i] && !us[s + 1 - i])
		{
			sol.push_back(i);
			sol.push_back(s + 1 - i);
			us[i] = 1;
			us[s + 1 - i] = 1;
			--l;
		}
	}

	printf("%d\n%d", (int) sol.size(), sol[0]);
	for (int i = 1; i < (int) sol.size(); ++i)
		printf(" %d", sol[i]);
	printf("\n");
	return 0;
}