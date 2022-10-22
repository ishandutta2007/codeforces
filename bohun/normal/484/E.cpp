#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 1e5 + 5, pod = (1 << 17);

int n;
int t[nax];
int T;
int fre = 1;

struct Node {
	int pref, suf, maxi, len;
	int l, r;
	Node () {}
	Node (int a, int b, int c, int d) {
		pref = a;
		suf = b;
		maxi = c;
		len = d;
	}
};

Node d[6000005];

vector <int> v, e[nax];
map <int, int> mapa, mapa2;
int root[nax];
int pr = 0;

Node akt(Node a, Node b) {
	Node odp = Node(0, 0, 0, 0);
	odp.len = a.len + b.len;
	odp.maxi = max({a.maxi, b.maxi, a.suf + b.pref});
	odp.pref = a.pref;
	odp.suf = b.suf;
	if(a.pref == a.len)
		odp.pref += b.pref;
	if(b.suf == b.len)
		odp.suf += a.suf;
	return odp;
}


void Build(int node = 0, int le = 0, int pr = pod - 1) {
	if(le == pr) {
		d[node] = Node(0, 0, 0, 1);
		return ;
	}
	int mid = (le + pr) / 2;
	d[node].l = fre++;
	d[node].r = fre++;
	Build(d[node].l, le, mid);
	Build(d[node].r, mid + 1, pr);
	int L = d[node].l, R = d[node].r;
	d[node] = akt(d[d[node].l], d[d[node].r]);
	d[node].l = L, d[node].r = R;
}

int Add(int pos, int id, int le = 0, int pr = pod - 1) {
	int ja = fre++;
	if(le == pos && pr == pos) {
		d[ja] = Node(1, 1, 1, 1);
		return ja;
	}
	int mid = (le + pr) / 2;
	d[ja].l = d[id].l;
	d[ja].r = d[id].r;
	if(pos <= mid) {
		d[ja].l = Add(pos, d[ja].l, le, mid);
	}
	else {
		d[ja].r = Add(pos, d[ja].r, mid + 1, pr);
	}
	int L = d[ja].l, R = d[ja].r;
	d[ja] = akt(d[d[ja].l], d[d[ja].r]);
	d[ja].l = L, d[ja].r = R;
	return ja;
}
	
	
void Go() {
	Build();	
	root[pr] = 0;
	int last = 0;
	for(int i = pr - 1; i >= 0; --i) {
		for(auto it: e[i]) {
			root[i] = Add(it, last);
			last = root[i];
		}
	}
	
	
}

vector <Node> res;

void daj(int x, int y, int id, int le = 0, int pr = pod - 1) {
	if(y >= pr && le >= x) {
		res.pb(d[id]);
		return ;
	}
	int mid = (le + pr) / 2;
	if(mid >= x) 
		daj(x, y, d[id].l, le, mid);
	if(y > mid)
		daj(x, y, d[id].r, mid + 1, pr);
}
	
		


int ok(int l, int r, int val) {
	res.clear();
	daj(l, r, root[val]);
	Node ha = res[0];
	for(int i = 1; ss(res) > i; ++i) 
		ha = akt(ha, res[i]);
	return ha.maxi;
}
		
		
	

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		v.pb(t[i]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(auto it: v) {
		mapa[it] = pr++;
		mapa2[pr - 1] = it;
	}
	for(int i = 1; i <= n; ++i) {
		t[i] = mapa[t[i]];
		e[t[i]].pb(i);
	}
	Go();
	cin >> T;
	while(T--) {
		int le, prr, w;
		cin >> le >> prr >> w;
		
		int lewo = 0;
		int prawo = pr - 1;
		while(prawo > lewo) {
			int mid = (lewo + prawo + 1) / 2;
			if(ok(le, prr, mid) >= w) {
				lewo = mid;
			}
			else {
				prawo = mid - 1;
			}
		}
		cout << mapa2[lewo] << endl;
		
	}
	
	
	
	
			
	
	
		
	
    return 0;
}