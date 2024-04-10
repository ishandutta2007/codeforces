#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+2, BASE = 131, MOD = 1e9+9, MOD2 = 696969697, INV2 = 159611381,LOG = __lg(MN) + 2, INV = 526717562;
struct Trie {
	struct Node {
		Node *c[2]; int mn;
		Node (int v) {mn=v;c[0]=c[1]=NULL;}
	} *rt;
	void insert (int x) {
		if (!rt) rt = new Node(x);
		Node *cur = rt;
		for (int i = 16; ~i; i--) {
			Node *&go = cur->c[x>>i&1];
			if (!go) go = new Node(x);
			else go->mn = min(go->mn,x);
			cur = go;
		}
	}
	int query (int bits, int leq) {
		if (!rt) return -1;
		Node *cur = rt; int ret = 0;
		for (int i = 16; ~i; i--) {
			bool go = bits>>i&1;
			if (cur->c[go^1] && cur->c[go^1]->mn <= leq) ret ^= 1 << i, cur = cur->c[go^1];
			else if (cur->c[go] && cur->c[go]->mn <= leq) cur = cur->c[go];
			else return -1;
		}
		return ret;
	}
} tr[MN];
int main () {
	int q; set<int> st;
	scanf ("%d",&q);
	while (q--) {
		int t;
		scanf ("%d",&t);
		if (t == 1) {
			int x;
			scanf ("%d",&x);
			if (st.count(x)) continue;
			st.insert(x);
			for (int i = 1; i * i <= x; i++) if (x % i == 0) {
				tr[i].insert(x);
				if (x / i != i) tr[x/i].insert(x);
			}
		} else {
			int x,k,s;
			scanf ("%d %d %d",&x,&k,&s);
			if (x % k) {printf ("-1\n"); continue;}
			int ret = tr[k].query(x,s-x);
			printf ("%d\n",~ret ? ret ^ x : ret);
		}
	}
    return 0;
}