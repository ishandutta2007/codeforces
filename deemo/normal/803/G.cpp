#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;
const int LOG = 90;
const int INF = 2e9;
const int XX = 1e5 + 10;

int n, k, a[MAXN], mn;
int weed[LOG*MAXN], le[LOG*MAXN], ri[LOG*MAXN], nut[LOG*MAXN], sz, ss[20][XX], gg[XX];

void absorb(int id){
	if (~nut[id]){
		weed[le[id]] = nut[le[id]] = nut[id];
		weed[ri[id]] = nut[ri[id]] = nut[id];
		nut[id] = -1;
	}
}

void smin(int &x, int y){x = min(x, y);}

int get(int l, int r){
	int ln = r-l;
	return min(ss[gg[ln]][l], ss[gg[ln]][r-(1<<gg[ln])]);
}

int create(int l, int r){
	sz++;
	weed[sz] = INF;
	if (l/n != r/n){
		smin(weed[sz], get(l%n, n));
		l += n-l%n;
		if (l < r){
			if (l/n != r/n)
				smin(weed[sz], mn);
			else
				smin(weed[sz], get(0, r%n));
		}
	}
	else smin(weed[sz], get(l%n, r%n));
	return sz;
}

void water(int id, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		weed[id] = nut[id] = x;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	if (!le[id]) le[id] = create(b, mid);
	if (!ri[id]) ri[id] = create(mid, e);
	absorb(id);

	water(le[id], b, mid, l, r, x);
	water(ri[id], mid, e, l, r, x);
	weed[id] = min(weed[le[id]], weed[ri[id]]);
}

int smoke(int id, int b, int e, int l, int r){
	if (l <= b && e <= r) return weed[id];
	if (r <= b || e <= l) return INF;

	int mid = b + e >> 1;
	if (!le[id]) le[id] = create(b, mid);
	if (!ri[id]) ri[id] = create(mid, e);
	absorb(id);
	return min(smoke(le[id], b, mid, l, r), smoke(ri[id], mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << sizeof(weed) << endl;
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> a[i], ss[0][i] = a[i];
	for (int w = 1; w < 20; w++)
		for (int i = 0; i < n; i++)
			if (i+(1<<w-1) < n)
				ss[w][i] = min(ss[w - 1][i], ss[w - 1][i + (1<<w-1)]);
			else
				ss[w][i] = ss[w - 1][i];
	for (int i = 1; i < XX; i++){
		int cur = 0;
		while ((1<<cur+1) <= i) cur++;
		gg[i] = cur;
	}
	{
		weed[++sz] = *min_element(a, a + n);
	}
	mn = *min_element(a, a + n);
	memset(nut, -1, sizeof(nut));
	weed[0] = INF;


	int q;	cin >> q;
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int l, r, x; cin >> l >> r >> x, l--;
			water(1, 0, n*k, l, r, x);
		}
		else{
			int l, r;	cin >> l >> r, l--;
			cout << smoke(1, 0, n*k, l, r) << "\n";
		}
	}
	return 0;
}