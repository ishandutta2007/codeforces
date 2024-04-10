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
int a[200000];
int cnt[200001];
int tree[524288];
bool chk[200001];
void update(int Node, int S, int E, int k)
{
	tree[Node]++;
	if (S == E)return;
	if ((S + E) / 2 >= k)update(2 * Node, S, (S + E) / 2, k);
	else update(2 * Node + 1, (S + E) / 2 + 1, E, k);
}
void update2(int Node, int S, int E, int k)
{
	tree[Node]--;
	if (S == E)return;
	if ((S + E) / 2 >= k)update2(2 * Node, S, (S + E) / 2, k);
	else update2(2 * Node + 1, (S + E) / 2 + 1, E, k);
}
int find(int Node, int S, int E, int k)
{
	if (S == E)return S;
	if (k <= tree[Node * 2])return find(2 * Node, S, (S + E) / 2, k);
	else return find(2 * Node + 1, (S + E) / 2 + 1, E, k - tree[2 * Node]);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0) update(1, 1, n, i);
	printf("%d\n", tree[1]);
	for (int i = 0; i < n; i++)
	{
		if (cnt[a[i]] == 1)continue;
		int t = find(1, 1, n, 1);
		if (!chk[a[i]] && a[i] < t)
		{
			chk[a[i]] = 1;
			continue;
		}
		cnt[a[i]]--;
		a[i] = t;
		update2(1, 1, n, t);
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}