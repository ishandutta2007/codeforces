#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 351D Jeff and Removing Periods - SEGTREE
 *
 * - given a sequence a, length up to n = 1e5
 * - given queries li, ri, up to 1 = 1e5 queries
 * - an OPERATION is:
 *   1. take v,t,k such that a_v = a_{v+t} = a_{v+2t} = ... a_{v+tk}
 *   2. remove all of those a[v]. etc
 *   3. permute a as you wish (after removing remaining elements)
 * - BEAUTY = # of operations on a sequence to remove all elements
 * - Q: for each query, what's the beauty of subarray a[li] to a[ri], inclusive
 *
 * NOTES
 */

struct segtree {
	vector<int> d;
	int h, n;
	segtree(int sz) {
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1<<h;
		d = vector<int>(n<<1, 0);
	}
	void update(int l, int r, int val) {
		for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
			if(l%2) d[l++] += val;
			if(r%2) d[--r] += val;
		}
	}
	int query(int i) {
		int sm = 0;
		for(i+=n;i>0;i/=2) sm += d[i];
		return sm;
	}
};


struct qry{
	int l, r, ind;
	bool operator< (const qry& o) const {
		//if(l == o.l) return r < o.r;
		return l > o.l;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int M, Q;
	cin >> M;
	vector<int> b(M);
	for(int i=0;i<M;++i)
		cin >> b[i] ;
	cin >> Q;
	vector<qry> q(Q);
	vector<bool> fnda(Q, false), fndb(Q, false);
	for(int i=0;i<Q;++i) {
		cin >> q[i].l >> q[i].r;
		--q[i].l; --q[i].r;
		q[i].ind = i; 
		fnda[i] = true;
	}
	sort(q.begin(), q.end());
	//cerr;for(int i=0;i<q.size();++i) {
		//cerr << "Q: " << q[i].l << " " << q[i].r << " " << q[i].i << endl;
	//cerr;}

	segtree ncol(M), nseq(M);
	vector<int> nxt(M, -1);
	map<int, int> mp;
	for(int i=M-1;i>=0;--i) {
		if(mp.count(b[i]) != 0)
			nxt[i] = mp[b[i]];
		mp[b[i]] = i;
	}
	//cerr << "::";
	//cerr; for(int i=0;i<M;++i)
		//cerr << nxt[i] << " ";
	//cerr << endl;

	vector<int> lastValid(1e5+5, M);
	vector<int> answers(Q);

	int qit = 0;
	for(int i=M-1;i>=0;--i) {
		if(nxt[i] == -1) {
			//cerr << "!!" << endl;
			ncol.update(i, M, 1);
			nseq.update(i, M, 1);
		} else {
			ncol.update(nxt[i], M, -1);
			ncol.update(i, M, 1);
			nseq.update(nxt[i], M, -1);
			nseq.update(i, M, 1);
			if(nxt[nxt[i]] != -1) {
				if(nxt[i]-i != nxt[nxt[i]]-nxt[i]) {
					nseq.update(nxt[nxt[i]], lastValid[b[i]], -1);
					lastValid[b[i]] = nxt[nxt[i]];
				}
			}
		}

		//cerr << i << ": " << endl;
		//cerr; for(int j=0;j<M;++j)
			//cerr << ncol.query(j) << " ";
		//cerr << endl;
		
		//cerr << q[qit].l << " vs " << i <<" ," << qit << " vs " << M << endl;
		for(;qit < Q && q[qit].l == i;++qit) {
			answers[q[qit].ind] = ncol.query(q[qit].r) + (nseq.query(q[qit].r) == 0);
		}
	}

	for(int i=0;i<Q;++i) {
		cout << answers[i] << endl;
	}

	return 0;
}