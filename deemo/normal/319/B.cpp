#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int max_n = 1e5 + 20;

int n;
vector<int>	vec, d;
vector<pair<int, int>>	st;
int seg[6 * max_n];

void modify(int v, int b, int e, int ind, int x){
	if (ind >= e || ind < b)	return;
	if (e - b == 1){
		seg[v] = x;
		return;
	}
	int mid = (b + e) / 2;
	modify(v<<1, b, mid, ind, x);
	modify(v<<1^1, mid, e, ind, x);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int get(int v, int b, int e, int l, int r){
	if (l >= e || b >= r)	return 0;
	if (l <= b && e <= r)	return	seg[v];
	int mid = (b + e) / 2;
	return	max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	d.resize(n);
	d[0] = 0;
	st.push_back({vec[0], 0});
	int ans = 0;

	for (int i = 1; i < n; i++){
		int t = vec[i];
		while (st.size() && st.back().first < t)
			st.pop_back();

		if (st.empty()){
			st.push_back({t, i});
			d[i] = 0;
			continue;
		}

		int temp = st.back().second;
		if (temp == i - 1)
			d[i] = 1;
		else{
			int z = get(1, 0, n, temp + 1, i);
			d[i] = z + 1;
		}
		
		ans = max(d[i], ans);
		modify(1, 0, n, i, d[i]);
		st.push_back({t, i});
	}
	printf("%d\n", ans);
	return 0;
}