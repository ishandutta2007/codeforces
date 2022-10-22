//If you're looking for love, know that love don't live here anymore..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include<utility>

using namespace std;

const int SQRT = 340;
const int MAXN = 1e5 + 30;

int n, m;
deque<int>	q[SQRT];
int mp[SQRT][MAXN];
int vec[MAXN];

void init(){
	for (int i = 0, id = 0; i < n; i += SQRT, id++)
		for (int j = i; j < i + SQRT && j < n; j++){
			mp[id][vec[j]]++;
			q[id].push_back(vec[j]);
		}
}

void shift(int l, int r){
	r--;
	int t = q[r/SQRT][r%SQRT];
	mp[r/SQRT][t]--;
	mp[l/SQRT][t]++;

	q[r/SQRT].erase(q[r/SQRT].begin() + r % SQRT);
	int tt = t;

	for (int id = l/SQRT; id < r/SQRT; id++){
		t = q[id].back();
		q[id].pop_back();
		mp[id][t]--;

		q[id + 1].push_front(t);
		mp[id + 1][t]++;
	}
	q[l/SQRT].insert(q[l/SQRT].begin() + (l % SQRT), tt);
}

int get(int l, int r, int k){
	int ret = 0;
	for (; l % SQRT != 0 && l < r; l++)
		if (q[l/SQRT][l%SQRT] == k)	ret++;
	
	for (; l / SQRT < r/SQRT; l += SQRT)
		ret += mp[l/SQRT][k];
	
	for (; l < r; l++)
		if (q[l/SQRT][l%SQRT] == k)	ret++;
	return	ret;
}	

int main(){
	scanf("%d", &n);	
	for (int i = 0; i < n; i++)	scanf("%d", &vec[i]);
	init();

	scanf("%d", &m);
	int last = 0;
	while (m--){
		int type;	scanf("%d", &type);
		if (type == 1){
			int tl, tr;	scanf("%d%d", &tl, &tr);
			int l = ((tl + last - 1) % n) + 1, r = ((tr + last - 1) % n) + 1;	
			if (l > r)	swap(l, r);
			l--;
			shift(l, r);
		}
		else{
			int tl, tr, tk;	scanf("%d%d%d", &tl, &tr, &tk);
			int l = ((tl + last - 1) % n) + 1, r = ((tr + last - 1) % n) + 1;
			int k = ((tk + last - 1) % n) + 1;
			if (l > r)	swap(l, r);
			l--;
			last = get(l, r, k);
			printf("%d\n", last);
		}
	}
	return 0;	
}