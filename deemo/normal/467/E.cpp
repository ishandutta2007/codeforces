#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 5e5 + 30;

int n;
vector<int>	ans;
int vec[MAXN], sec[MAXN];
map<int, int>	mp;
int smp[MAXN];
vector<int>	save[MAXN];
int seg[4 * MAXN], maxi[4 * MAXN];
int l;

void modify(int v, int b, int e, int x, int val){
	if (e - b == 1){
		seg[v] = vec[b];
		maxi[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		modify(v<<1, b, mid, x, val);
	else
		modify(v<<1^1, mid, e, x, val);
	if (maxi[v<<1] > maxi[v<<1^1]){
		maxi[v] = maxi[v<<1];
		seg[v] = seg[v<<1];
	}
	else{
		maxi[v] = maxi[v<<1^1];
		seg[v] = seg[v<<1^1];
	}
}

void erase(int r){
	for (; l < r; l++){
		save[vec[l]].clear();
		modify(1, 0, n, l, -1);
	}
}

pair<int, int>	get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	
		return	{maxi[v], seg[v]};
	if (r <= b || e <= l)
		return	{-1, -1};

	int mid = (b + e)/ 2;
	return	max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &vec[i]);
	copy(vec, vec + n, sec);
	sort(sec, sec + n);
	int sz = unique(sec, sec + n) - sec;
	for (int i = 0; i < sz; i++){
		mp[sec[i]] = i;
		smp[i] = sec[i];
	}
	for (int i = 0; i < n; i++)	vec[i] = mp[vec[i]];

	for (int i = 0; i < n; i++){
		int x = vec[i];

		bool fl = 0;
		for (int y:save[x]){
			pair<int, int>	mx = get(1, 0, n, 0, y);
			if (mx.first <= y)	continue;
			ans.push_back(mx.second);
			ans.push_back(x);
			ans.push_back(mx.second);
			ans.push_back(x);
			erase(i + 1);
			fl = 1;
			break;
		}
		
		if (!fl){
			save[x].push_back(i);
			for (int y:save[x])
				modify(1, 0, n, y, i);
		}
	}

	printf("%d\n", (int)ans.size());
	for (int u:ans)
		printf("%d ", smp[u]);
	printf("\n");
	return 0;
}