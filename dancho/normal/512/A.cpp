#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
char s[128][128];

vector<int> g[32];
int din[32];
bool us[32];

vector<char> ans;

void add_edge(int a, int b)
{
	//~ printf("ADD_ED %d %d\n", a, b);
	++din[b];
	g[a].push_back(b);
}

void dfs(int v)
{
  ans.push_back(v);
  for (int i = 0; i < (int) g[v].size(); ++i)
  {
    int u = g[v][i];
    if (!us[u])
    {
      --din[u];
      if (!din[u])
      {
        us[u] = 1;
        dfs(u);
      }
    }
  }
}

int main()
{
	memset(din, 0, sizeof(din));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}

	for (int i = 0; i + 1 < n; ++i)
	{
		int j = 0, k = 0;
		int lc = strlen(s[i]), ln = strlen(s[i + 1]);
		while (j < lc && k < ln)
		{
			if (s[i][j] != s[i + 1][k])
			{
				break;
			}
			++j;
			++k;
		}
		if (j < lc && k == ln)
		{
			//~ fprintf(stderr, "1\n");
			printf("Impossible\n");
			return 0;
		}

		if (j < lc && k < ln)
		{
			add_edge(s[i][j] - 'a', s[i + 1][k] - 'a');
		}
	}

	memset(us, 0, sizeof(us));
	for (int i = 0; i < 26; ++i)
	{
		if (!din[i] && !us[i])
		{
			us[i] = 1;
      dfs(i);
		}
	}

  if (ans.size() != 26)
  {
			//~ fprintf(stderr, "%d\n", (int) ans.size());
			//~ fprintf(stderr, "1\n");
    printf("Impossible\n");
  }
  else
  {
    for (int i = 0; i < 26; ++i)
    {
      printf("%c", 'a' + ans[i]);
    }
    printf("\n");
  }

	return 0;
}