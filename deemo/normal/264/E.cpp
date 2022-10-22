//I used to have a little bit of a plan
//Used to have a concept of where I stand
//But that concept slipped right out of my hand
//Now I don't really even know who I am..

#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int MAXN = 2e5 + 10;

int n, q, h[MAXN], p[MAXN], type[MAXN], posy[MAXN], xx[MAXN], weed[2][4 * MAXN], gec[MAXN];
pair<int, int>	sec[MAXN];
set<pair<int, int>>	sety;
set<int>	setx;

void water(int g, int v, int b, int e, int pos, int val){
	if (e - b == 1){
		weed[g][v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (pos < mid)
		water(g, v<<1, b, mid, pos, val);
	else
		water(g, v<<1^1, mid, e, pos, val);
	weed[g][v] = max(weed[g][v<<1], weed[g][v<<1^1]);
}

int smoke(int g, int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[g][v];
	if (r <= b || e <= l)	return 0;

	int mid = (b + e)/ 2;
	return max(smoke(g, v<<1, b, mid, l, r), smoke(g, v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++){
		scanf("%d %d", &type[i], &p[i]), type[i]--, p[i]--;
		if (!type[i])
			scanf("%d", &h[p[i]]), h[p[i]] -= i;
	}
	
	for (int i = 0; i < n; i++)	sec[i] = {h[i], i};
	sort(sec, sec + n);
	for (int i = 0; i < n; i++)	posy[sec[i].second] = i;

	for (int i = 0; i < q; i++){
		if (!type[i]){
			int v = p[i], t = 0;
			while (!sety.empty() && sety.begin()->first <= h[v]){
				int u = sety.begin()->second;
				xx[u] = 0;
				water(0, 1, 0, n, u, 0);//x
				water(1, 1, 0, n, posy[u], 0);//y
				gec[t++] = u;
				sety.erase(sety.begin());
			}

			xx[v] = smoke(0, 1, 0, n, v, n) + 1;
			sety.insert({h[v], v});
			setx.insert(v);
			water(0, 1, 0, n, v, xx[v]);//x
			water(1, 1, 0, n, posy[v], xx[v]);//y

			while (t){
				int u = gec[--t];
				xx[u] = smoke(0, 1, 0, n, u, n) + 1;
				water(0, 1, 0, n, u, xx[u]);//x
				water(1, 1, 0, n, posy[u], xx[u]);//y
				sety.insert({h[u], u});
			}
		}	
		else{
			int t = 0;
			auto it = setx.begin();
			for (int j = 0; j < p[i]; j++, it++){
				int u = *it;
				water(0, 1, 0, n, u, 0);//x
				water(1, 1, 0, n, posy[u], 0);//y
				gec[t++] = u;
			}
			int v = *it;
			xx[v] = 0;
			setx.erase(it);
			sety.erase({h[v], v});
			water(0, 1, 0, n, v, xx[v]);//x
			water(1, 1, 0, n, posy[v], xx[v]);//y

			while (t){
				int u = gec[--t];
				xx[u] = smoke(1, 1, 0, n, posy[u], n) + 1;
				water(0, 1, 0, n, u, xx[u]);//x
				water(1, 1, 0, n, posy[u], xx[u]);//y
			}
		}
		printf("%d\n", weed[0][1]);
	}
	return 0;
}