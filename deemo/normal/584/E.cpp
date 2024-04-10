#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int MAXN = 2e3 + 10;

int n, a[MAXN], b[MAXN], pos[MAXN], ans, sz;
int	vec[MAXN * MAXN];
int sec[MAXN * MAXN];
set<int>	fs, sc;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]),	pos[a[i]] = i;
	for (int i = 0; i < n; i++)	b[i] = pos[b[i]];
	for (int i = 0; i < n; i++)	ans += abs(b[i] - i);
	ans/=2;
	for (int i = 0; i < n; i++)
		if (b[i] > i)	fs.insert(i);
		else if (b[i] < i)	sc.insert(i);

	while (sc.size()){
		auto it = sc.begin();
		auto it2 = fs.lower_bound(*it);
		it2--;
		vec[sz] = *it + 1;
		sec[sz++] = *it2 + 1;
		swap(b[*it], b[*it2]);
		int aa = *it, bb = *it2;
		sc.erase(it);
		fs.erase(it2);
		
		if (b[aa] > aa)
			fs.insert(aa);
		if (b[bb] < bb)
			sc.insert(bb);
	}
	
	printf("%d\n", ans);
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d %d\n", vec[i], sec[i]);
	return	0;
}