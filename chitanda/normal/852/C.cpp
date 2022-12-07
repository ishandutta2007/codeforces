#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 51000;

int N;
int number[NMAX], ans[NMAX];
vector<pair<int, int> > Q;

int main()
{
	int i;
	scanf("%d", &N);
	for(i = 0;i < N;i += 1)
		scanf("%d", &number[i]);
	for(i = 0;i < N;i += 1)
		Q.push_back(make_pair(number[i] + number[(i + 1) % N], i));
	sort(Q.begin(), Q.end());
	for(i = 0;i < N;i += 1)
		ans[Q[i].second] = i;
	for(i = 0;i < N;i += 1)
		printf("%d%c", ans[i], " \n"[i + 1 == N?1:0]);
	exit(0);
}