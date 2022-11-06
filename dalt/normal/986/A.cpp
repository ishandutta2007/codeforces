#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<random>

#define foreach(var, list, type) for (type::iterator var = list.begin(); var != list.end(); var++)
#define INF 100000000
#define LIMIT 100
class Node {
public:
	Node() : children(),dp(LIMIT+1){
		for (int i = 1; i <= LIMIT; i++)
		{
			dp[i] = (INF);
		}
	}
	~Node() {
	}
	std::vector<Node *> children;
	std::vector<int> dp;
	int goods;
};

int int_cmp(void const *a, void const*b) {
	int av = *(int *)a;
	int bv = *(int *)b;
	return av - bv;
}

Node nodes[100001];

#if (defined CF986A) || (defined ONLINE_JUDGE)
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\CF986A.in", "r", stdin);
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\CF986A.out", "w", stdout);
#endif

	int n, m, k, s;
	scanf("%d %d %d %d", &n, &m, &k, &s);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &nodes[i].goods);
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		nodes[a].children.push_back(&nodes[b]);
		nodes[b].children.push_back(&nodes[a]);
	}

	std::deque<Node *> *deque = new std::deque<Node *>();
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (nodes[j].goods != i)
			{
				continue;
			}
			deque->push_back(&nodes[j]);
			nodes[j].dp[i] = 0;
		}

		while (!deque->empty())
		{
			Node *head = deque->front();
			deque->pop_front();

			foreach(iter, head->children, std::vector<Node*>)
			{
				Node *child = *iter;
				if (child->dp[i] != INF)
				{
					continue;
				}
				child->dp[i] = head->dp[i] + 1;
				deque->push_back(child);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		Node &node = nodes[i];
		std::sort(node.dp.begin() + 1, node.dp.end());
		int sum = 0;
		for (int i = 1; i <= s; i++)
		{
			sum += node.dp[i];
		}
		printf("%d ", sum);
	}

	return 0;
}
#endif