#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

#define Thing pair<pair<int, int>, int>
#define A first.first
#define B first.second
#define C second

const int MAXN = 5e5 + 10;

int n, sec[MAXN], weed[4 * MAXN];
Thing vec[MAXN];
map<int, int>	mp;

bool cmp(Thing a, Thing b){return	a.A > b.A;}

void water(int v, int b, int e, int x, int val){
	if (e - b == 1){
		weed[v] = max(val, weed[v]);
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val);
	else
		water(v<<1^1, mid, e, x, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r){
	if (r <= b)	return 0;
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	return	max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i].A);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i].B);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i].C);
	sort(vec, vec + n, cmp);

	for (int i = 0; i < n; i++)	sec[i] = vec[i].B;
	sort(sec, sec + n);
	for (int i = 0; i < n; i++)
		if (mp.count(sec[i]) == 0)	mp[sec[i]] = i;
	for (int i = 0; i < n; i++)
		vec[i].B = mp[vec[i].B];

	int cn = 0;
	for (int i = 0; i < n;){
		int j = i;
		while (j < n && vec[i].A == vec[j].A){
			int mx = smoke(1, 0, n, vec[j].B + 1, n);
			if (mx > vec[j].C)	cn++;
			j++;
		}
		for (; i < j; i++)
			water(1, 0, n, vec[i].B, vec[i].C);
	}
	printf("%d\n", cn);
	return	0;
}