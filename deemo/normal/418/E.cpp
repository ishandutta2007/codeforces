#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;
const int SQ = 530;
const int ZZ = 330;

int n, arr[MAXN], f[2 * MAXN], cc, id[MAXN], prv[MAXN], cnt[ZZ][2*MAXN], fen[ZZ][MAXN], gg[2 * MAXN], tot[MAXN];
bool mark[2 * MAXN];
map<int, int>	mp;

int get(int w, int v){
	int ret = 0;
	for (; v; v -= v&-v)
		ret += fen[w][v];
	return ret;
}

void add(int w, int v, int val){
	tot[w] += val;
	for (; v < MAXN; v += v&-v)
		fen[w][v] += val;
}

void update(int w, int v, int val){
	if (cnt[w][v])
		add(w, cnt[w][v], -1);
	cnt[w][v] += val;
	if (cnt[w][v])
		add(w, cnt[w][v], 1);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (mp.count(arr[i]) == 0)	f[cc] = arr[i], mp[arr[i]] = cc++;
		arr[i] = mp[arr[i]];
	}

	for (int i = 0, w = 0; i < n; i += SQ, w++){
		id[i] = w;
		if (w)
			for (int j = 0; j < n && cnt[w-1][j]; j++)
				cnt[w][j] = cnt[w - 1][j];

		for (int j = i; j < n && j < i + SQ; j++){
			prv[j] = i;
			cnt[w][arr[j]]++;
		}

		for (int j = 0; j < n && cnt[w][j]; j++)
			add(w, cnt[w][j], 1);
	}	

	int q;	scanf("%d", &q);
	while (q--){
		int type;	scanf("%d", &type), type--;
		if (type){
			int x, y;	scanf("%d %d", &x, &y), x--, y--;
			if (x == 0)	printf("%d\n", f[arr[y]]);
			else{
				x = (x + 1) % 2;	

				int z = cnt[id[prv[y]]][arr[y]];
				for (int i = y+1; i < n && prv[i] == prv[y]; i++)
					if (arr[i] == arr[y])	z--;
	
				if (!x)
					printf("%d\n", z);
				else{
					int pr = prv[y];
					int ret = (id[pr]==0?0:tot[id[pr] - 1] - get(id[pr] - 1, z - 1));
			
					for (int i = pr; i <= y; i++){
						if (mark[arr[i]] == 0)	
							gg[arr[i]] = (id[pr]?cnt[id[pr] - 1][arr[i]]:0);
						mark[arr[i]] = 1;
						if (gg[arr[i]] >= z)	continue;
						gg[arr[i]]++;
						if (gg[arr[i]] >= z)	ret++;
					}
					
					for (int i = pr; i <= y; i++)
						mark[arr[i]] = 0;
					printf("%d\n", ret);
				}
			}
		}
		else{
			int p, v;	scanf("%d %d", &v, &p), p--;
			if (mp.count(v) == 0)	f[cc] = v, mp[v] = cc++;
			v = mp[v];
			for (int i = prv[p]; i < n; i += SQ)
				update(id[i], arr[p], -1);

			arr[p] = v;
			for (int i = prv[p]; i < n; i += SQ)
				update(id[i], arr[p], 1);
		}
	}
	return 0;
}