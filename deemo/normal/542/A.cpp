//I know that Diamonds mean money for this art, but That's not the Shape of My Heart..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

#define Thing pair<pair<int, int>, int>
#define L first.first
#define R first.second
#define ID second

const int MAXN = 2e5 + 10;

int n, m, tx, weed[2][4 * MAXN];
Thing	vec[MAXN], sec[MAXN];
int vv[MAXN], ss[MAXN], gec[MAXN];
int tl[MAXN], tr[MAXN], val[MAXN];


bool cmp(Thing a, Thing b){return a.R < b.R;}

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[0][v] = vec[b].R - vec[b].L;
		weed[1][v] = sec[b].R - sec[b].L;
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	for (int i = 0; i < 2; i++)
		weed[i][v] = max(weed[i][v<<1], weed[i][v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r, int t){
	if (l <= b && e <= r)
		return	weed[t][v];
	if (r <= b || e <= l)
		return	-1;

	int mid = (b + e)/ 2;
	return	max(smoke(v<<1, b, mid, l, r, t), smoke(v<<1^1, mid, e, l, r, t));
}

bool ok(int ind, int mid){
	int p1 = lower_bound(vv, vv + n, tl[ind] + mid) - vv;
	int p2 = upper_bound(vv, vv + n, tr[ind]) - vv;
	if (p1 < p2 && smoke(1, 0, n, p1, p2, 0) >= mid)	return	true;

	p1 = upper_bound(ss, ss + n, tr[ind] - mid) - ss;
	p2 = lower_bound(ss, ss + n, tl[ind]) - ss;
	if (p2 < p1 && smoke(1, 0, n, p2, p1, 1) >= mid)	return	true;
	return	false;
}

ll get(int ind){
	if (tx >= tr[ind])
		return (ll)val[ind] * (ll)(tr[ind] - tl[ind]);
	int b = 1, e = tr[ind] - tl[ind], ret = 0;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (ok(ind, mid))
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	return	ll(ret) * (ll)val[ind];
}

bool cmp2(int u, int v){return tl[u] < tl[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> vec[i].L >> vec[i].R, vec[i].ID = i;
	sort(vec, vec + n, cmp);
	copy(vec, vec + n, sec);
	sort(sec, sec + n);
	for (int i = 0; i < n; i++)
		vv[i] = vec[i].R;
	for (int i = 0; i < n; i++)
		ss[i] = sec[i].L;
	plant(1, 0, n);
	
	for (int i = 0; i < m; i++)
		cin >> tl[i] >> tr[i] >> val[i];
	iota(gec, gec + m, 0);
	sort(gec, gec + m, cmp2);

	int ind = -1, cur = 0;
	ll mx = 0;
	for (int j = 0; j < m; j++){
		int i = gec[j];
		while (cur < n && sec[cur].L <= tl[i])	tx = max(tx, sec[cur++].R);
		ll t = get(i);
		if (t > mx){
			mx = t;
			ind = i;
		}
	}		

	cout << mx << "\n";
	if (mx){
		int maxi = -1, id = -1;
		for (int i = 0; i < n; i++){
			int tt = max(0, min(vec[i].R, tr[ind]) - tl[ind]);
			tt -= max(0, vec[i].L - tl[ind]);

			if (tt > maxi){
				maxi = tt;
				id = vec[i].ID;
			}
		}
		cout << id + 1 << " ";
		cout << ind + 1 << "\n";
	}
	return	0;
}