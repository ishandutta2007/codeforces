#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<map>

using namespace std;

#define left first
#define right second

const int max_n = 3e5 + 100;
const int MAX = 1e6 + 10;

int n, q;
vector<pair<int, int>>	segment, vec;
vector<int>	query[max_n];
int seg[4 * (MAX + 10)];
map<pair<int, int>, int>	mp;

void add(int v, int b, int e, int x){
	if (e - b == 1){
		seg[v]++;
		return;
	}
	
	int mid = (b + e)/ 2;
	if (x < mid)	add(v<<1, b, mid, x);
	else	add(v<<1^1, mid, e, x);
	seg[v] = seg[v<<1] + seg[v<<1^1];
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	seg[v];
	if (r <= b || e <= l)	return	0;
	
	int mid = (b + e)/ 2;
	return	get(v<<1, b, mid, l, r) + get(v<<1^1, mid, e, l, r);
}

bool cmp(pair<int, int>	a, pair<int, int>	b){
	if (a.right != b.right)	
		return	a.right < b.right;
	return	a.left < b.left;
}

int main(){
	scanf("%d%d", &n, &q);
	segment.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &segment[i].left, &segment[i].right),	segment[i].left--;
	sort(segment.begin(), segment.end(), cmp);	

	for (int i = 0; i < q; i++){
		int t;	scanf("%d", &t);
		query[i].resize(t);
		for (int j = 0; j < t; j++){
			scanf("%d", &query[i][j]), query[i][j]--;
			if (j == 0)	vec.push_back({0, query[i][j]});
			else	vec.push_back({query[i][j - 1] + 1, query[i][j]});
		}
		vec.push_back({query[i][t - 1] + 1, 1e6});
	}
	sort(vec.begin(), vec.end(), cmp);
	
	int b = 0, c = 0;
	for (int i = 0; i < MAX - 7; i++){
		while (b < n && segment[b].right <= i){
			add(1, 0, MAX, segment[b].left);
			b++;
		}
		
		while (c < vec.size() && vec[c].right <= i){
			if (vec[c].right > vec[c].left)
				mp[vec[c]] = get(1, 0, MAX, vec[c].left, vec[c].right);
			c++;
		}
	}
	
	for (int i = 0; i < q; i++){
		int t = 0;
		for (int j = 0; j < query[i].size(); j++){
			if (j == 0)	t += mp[{0, query[i][j]}];
			else	t += mp[{query[i][j - 1] + 1, query[i][j]}];
		}
		t += mp[{query[i][query[i].size() - 1] + 1, 1e6}];
		printf("%d\n", n - t);
	}
	return 0;
}