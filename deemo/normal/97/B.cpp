#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, sz;
pair<int, int>	vec[MAXN], sec[MAXN];

void solve(int l, int r){
	if (r - l == 1)	return;
	
	int mid = l+r>>1;
	solve(l, mid);
	solve(mid, r);
	for (; l < r; l++)
		sec[sz++] = {vec[mid].F, vec[l].S};
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d %d", &vec[i].F, &vec[i].S), sec[sz++] = vec[i];
	sort(vec, vec + n);
	solve(0, n);

	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d %d\n", sec[i].F, sec[i].S);
	return 0;
}