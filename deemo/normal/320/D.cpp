#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 1e5 + 30;

int n;
int a[max_n], d[max_n];
int seg[4 * max_n], ind[4 * max_n];
vector<pair<int, int>>	st;

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	seg[v];
	if (r <= b || e <= l)	return	-1;

	int mid = (b + e)/ 2;
	return	max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void modify(int v, int b, int e, int u, int x){
	if (e - b == 1){
		seg[v] = x;
		return;
	}

	int mid = (b + e)/ 2;
	if (u < mid)	
		modify(v<<1, b, mid, u, x);
	else
		modify(v<<1^1, mid, e, u, x);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; i++){
		while (st.size() && st.back().first < a[i])	st.pop_back();
		if (st.empty())	d[i] = 0;
		else{
			if (st.back().second == i - 1)	d[i] = 1;
			else d[i] = get(1, 0, n, st.back().second + 1, i) + 1;
		}
		modify(1, 0, n, i, d[i]);
		st.push_back({a[i], i});
	}
	printf("%d\n", *max_element(d, d + n));
	return 0;
}