#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define Query pair<pair<int, int>, int>
#define ind first.first
#define val first.second
#define id second

const int MAXN = 4e5 + 20;

int n, q, vec[MAXN], llis[MAXN], rlis[MAXN], cnt[MAXN], ans[MAXN], weed[2][4 * MAXN];
pair<int, int>	sec[MAXN];
bool lovable[MAXN];
Query que[MAXN];

bool cmp(Query a, Query b){return a.val < b.val;}

void plant(int v = 1, int b = 0, int e = n){
	if (e - b == 1){
		weed[1][v] = rlis[b];
		return;	
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[1][v] = max(weed[1][v<<1], weed[1][v<<1^1]);
}

void water(int v, int b, int e, int x, int y, int t){
	if (e - b == 1){
		weed[t][v] = y;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, y, t);
	else
		water(v<<1^1, mid, e, x, y, t);
	weed[t][v] = max(weed[t][v<<1], weed[t][v<<1^1]);
}

int get(int v, int b, int e, int l, int r, int t){
	if (l == r)	return	0;
	if (l <= b && e <= r)	return	weed[t][v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	return	max(get(v<<1, b, mid, l, r, t), get(v<<1^1, mid, e, l, r, t));
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)	scanf("%d", &vec[i]);
	vector<int>	lis;
	for (int i = 0; i < n; i++){
		int pos = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
		if (pos == lis.size())
			lis.push_back(vec[i]);
		else
			lis[pos] = vec[i];
		
		llis[i] = pos + 1;
	}	
	int mx = lis.size();

	for (int i = 0; i < n; i++)	vec[i] *= -1;
	lis.clear();
 	for (int i = n - 1; i >= 0; i--){
		int pos = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
		if (pos == lis.size())
			lis.push_back(vec[i]);
		else
			lis[pos] = vec[i];

		rlis[i] = pos + 1;
	}
	for (int i = 0; i < n; i++)	vec[i] *= -1;

	for (int i = 0; i < n; i++)
		if (llis[i] + rlis[i] - 1 == mx)
			lovable[i] = 1, cnt[llis[i]]++;

	for (int i = 0; i < q; i++){
		scanf("%d %d", &que[i].ind, &que[i].val);	que[i].ind--;
		if (cnt[llis[que[i].ind]] == 1 && lovable[que[i].ind])	
			ans[i] = mx - 1;
		else
			ans[i] = mx;
		que[i].id = i;
	}
	sort(que, que + q, cmp);
	for (int i = 0; i < n; i++)	
		sec[i] = {vec[i], i};
	sort(sec, sec + n);

	plant();
	int b = 0, c = 0;
	for (int i = 0; i < q; i++){
		Query v = que[i];
		while (b < n && sec[b].first < v.val){
			water(1, 0, n, sec[b].second, llis[sec[b].second], 0);
			b++;
		}
		while (c < n && sec[c].first <= v.val)
			water(1, 0, n, sec[c++].second, 0, 1);

		ans[v.id] = max(ans[v.id], get(1, 0, n, 0, v.ind, 0) + 1 + get(1, 0, n, v.ind + 1, n, 1));
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	return	0;
}