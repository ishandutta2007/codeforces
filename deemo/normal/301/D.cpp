#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define L first.first
#define R first.second
#define ID second
#define Query pair<pair<int, int>, int>

const int MAXN = 2e5 + 10;

int n, q, ans[MAXN], fen[MAXN], pos[MAXN];
Query que[MAXN];
vector<int>	vec[MAXN];

void add(int v, int val){
	for (v++; v < MAXN; v += v&-v)
		fen[v] += val;
}

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

bool cmp(Query a, Query b){return a.R < b.R;}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++){
		int v;	scanf("%d", &v);
		pos[v] = i;
	}

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i){
			int mn = min(pos[i], pos[j]);
			int mx = max(pos[i], pos[j]);
			vec[mx].push_back(mn);
		}

	for (int i = 0; i < q; i++)
		scanf("%d %d", &que[i].L, &que[i].R), que[i].L--, que[i].ID = i;
	sort(que, que + q, cmp);
	int cur = 0;
	for (int i = 0; i < n; i++){
		for (int x:vec[i])	
			add(x, 1);
	
		while (cur < q && que[cur].R == i + 1)
			ans[que[cur].ID] = get(MAXN - 1) - get(que[cur].L), cur++;
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	return 0;
}