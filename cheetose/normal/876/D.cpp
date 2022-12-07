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
#define X first
#define Y second
#define INF 987654231
#define PI 3.14159265358979323
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
int a[300000], tree[1048576];
void update(int Node, int S, int E, int i)
{
	if (S == E)
	{
		tree[Node]++;
		return;
	}
	if (i <= (S + E) / 2) update(Node * 2, S, (S + E) / 2, i);
	else update(Node * 2 + 1, (S + E) / 2 + 1, E, i);
	if (tree[2 * Node] + 1 > 0)
	{
		tree[Node] = tree[2 * Node + 1];
		if (tree[2 * Node + 1] == E - (S + E) / 2)tree[Node] += tree[Node * 2];
	}
	else tree[Node] = 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	printf("1 ");
	for (int i = 0; i < n; i++)
	{
		update(1, 1, n, a[i]);
		printf("%d ", i+2-tree[1]);
	}
}