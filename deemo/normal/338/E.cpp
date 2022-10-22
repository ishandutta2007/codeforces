//Look for me in the white forest hiding in a hollow tree..

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 150000 + 50;

int n, m, h, vec[MAXN], sec[MAXN], ans, need[4*MAXN], ex[4*MAXN];

void plant(int v, int b, int e){
	need[v] = e - b;
	if (e - b == 1)	return;
	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
}

void water(int v, int b, int e, int x, int val){
	if (x == e)	return;
	if (e - b == 1){
		need[v] -= val;
		ex[v] = max(0, -need[v]);
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val);
	else
		water(v<<1^1, mid, e, x, val);
	
	need[v] = max(0, need[v<<1]) + max(0, need[v<<1^1] - ex[v<<1]);
	ex[v] = ex[v<<1^1] + max(0, ex[v<<1] - max(0, need[v<<1^1]));
}

int main(){
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++)	scanf("%d", &sec[i]);
	sort(sec, sec + m);
	plant(1, 0, m);
	for (int i = 0; i < n; i++){
		if (i >= m)
			water(1, 0, m, lower_bound(sec, sec + m, h - vec[i - m]) - sec, -1);
		scanf("%d", &vec[i]);
		water(1, 0, m, lower_bound(sec, sec + m, h - vec[i]) - sec, 1);
		ans += bool(need[1] == 0);
	}
	printf("%d\n", ans);
	return	0;	
}