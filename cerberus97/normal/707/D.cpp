#include <iostream>
#include <vector>

using namespace std;

const int Q = (int)1e5 + 5, N = (int)1e3 + 5;

bool shelf[N][N] = {0};
int ans[Q];

struct node
{
	int qid, i, j;
	vector <int> ch;

}tree[Q];

int invert(int i, int m)
{
	int temp = 0;

	for (int j = 1; j <= m; ++j)
	{
		if (shelf[i][j])
			--temp;

		else
			++temp;

		shelf[i][j] = !shelf[i][j];
	}

	return temp;
}

void dfs(int cur, int m, int curAns = 0)
{
	ans[cur] = curAns;

	for (vector <int>::iterator i = tree[cur].ch.begin(); i != tree[cur].ch.end(); ++i)
	{
		if (tree[*i].qid == 1)
		{
			bool wasHere = true;

			if(!shelf[tree[*i].i][tree[*i].j])
			{
				++curAns;
				wasHere = false;
			}				

			shelf[tree[*i].i][tree[*i].j] = true;

			dfs(*i, m, curAns);

			if (!wasHere)
			{
				shelf[tree[*i].i][tree[*i].j] = false;
				--curAns;
			}
		}

		else if (tree[*i].qid == 2)
		{
			bool wasHere = false;

			if(shelf[tree[*i].i][tree[*i].j])
			{
				--curAns;
				wasHere = true;
			}				

			shelf[tree[*i].i][tree[*i].j] = false;

			dfs(*i, m, curAns);

			if (wasHere)
			{
				shelf[tree[*i].i][tree[*i].j] = true;
				++curAns;
			}
		}

		else if (tree[*i].qid == 3)
		{
			curAns = curAns + invert(tree[*i].i, m);
			dfs(*i, m, curAns);
			curAns = curAns + invert(tree[*i].i, m);
		}

		else
		{
			dfs(*i, m, curAns);
		}
	}
}

int main()
{
	int n, m, q;
	cin >> n >> m >> q;

	tree[0].ch.push_back(1);

	for (int i = 1; i <= q; ++i)
	{
		cin >> tree[i].qid >> tree[i].i;

		if (tree[i].qid <= 2)
			cin >> tree[i].j;

		if (tree[i].qid == 4)
			tree[tree[i].i].ch.push_back(i);

		else
			tree[i-1].ch.push_back(i);
	}

	dfs(0, m);

	for (int i = 1; i <= q; ++i)
		cout << ans[i] << '\n';
}