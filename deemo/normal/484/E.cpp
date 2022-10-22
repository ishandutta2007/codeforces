#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define ANS pair<pair<int, int>, int>
#define MX first.first
#define LE first.second
#define RI second

const int MAXN = 2e5 + 3e4;
const int LOG = 20;

int root[MAXN], le[LOG * MAXN * 2], ri[LOG * MAXN * 2], sz, lleft[LOG * MAXN * 2], rright[LOG * MAXN * 2];
int maxi[LOG * MAXN * 2];
int n, q;
int h[MAXN], vec[MAXN];
pair<int, int>	sec[MAXN];

int build(int b, int e){
	int id = sz++;
	if (e - b == 1)	return	id;

	int mid = (b + e)/ 2;
	le[id] = build(b, mid);
	ri[id] = build(mid, e);
	return	id;
}

void merge(int id, int b, int e, int mid){
	maxi[id] = max(maxi[le[id]], maxi[ri[id]]);
	maxi[id] = max(maxi[id], rright[le[id]] + lleft[ri[id]]);

	lleft[id] = lleft[le[id]];
	if (lleft[id] == (mid - b))	lleft[id] += lleft[ri[id]];

	rright[id] = rright[ri[id]];
	if (rright[id] == (e - mid))	rright[id] += rright[le[id]];
}

int modify(int id, int b, int e, int x){
	int nid = sz++;
	if (e - b == 1){
		lleft[nid] = rright[nid] = maxi[nid] = 1;
		return	nid;
	}

	int mid = (b + e)/ 2;
	le[nid] = le[id];
	ri[nid] = ri[id];
	if (x < mid)
		le[nid] = modify(le[nid], b, mid, x);
	else
		ri[nid] = modify(ri[nid], mid, e, x);
		
	merge(nid, b, e, mid);
	return	nid;
}

ANS mg(ANS a, ANS b, int s1, int s2){
	ANS ret;
	ret.MX = max(a.MX, b.MX);
	ret.MX = max(ret.MX, a.RI + b.LE);

	ret.LE = a.LE;
	if (a.LE == s1)	ret.LE += b.LE;
	
	ret.RI = b.RI;
	if (b.RI == s2)	ret.RI += a.RI;
	return	ret;
}	

ANS get(int id, int b, int e, int l, int r){
	if (l <= b && e <= r)	
		return	{{maxi[id], lleft[id]}, rright[id]};
	if (r <= b || e <= l)
		return	{{0, 0}, 0};

	int mid = (b + e)/ 2;
	return	mg(get(le[id], b, mid, l, r), get(ri[id], mid, e, l, r), min(mid - b, max(0, mid - l)), min(e - mid, max(0, r - mid)));
}

void init(){
	copy(h, h + n, vec);
	sort(vec, vec + n);
	reverse(vec, vec + n);
	
	for (int i = 0; i < n; i++)
		sec[i] = {h[i], i};
	sort(sec, sec + n);
	reverse(sec, sec + n);

	root[0] = build(0, n);
	for (int i = 0; i < n; i++)
		root[i + 1] = modify(root[i], 0, n, sec[i].second);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> h[i];
	init();

	cin >> q;
	while (q--){
		int l, r, w;	cin >> l >> r >> w;	l--;
		int b = 0, e = n, mid, ret = n;
		while (b <= e){
			mid = (b + e)/ 2;
			if (get(root[mid], 0, n, l, r).MX >= w){
				ret = mid;
				e = mid - 1;
			}
			else	b = mid + 1;
		}
		cout << vec[ret - 1] << "\n";
	}
	return 0;
}