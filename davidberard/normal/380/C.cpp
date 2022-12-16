#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * 380C - Sereja and Brackets (SEGTREES!!)
 * Given a bracket sequence of length 1e6, answer 1e5 queries:
 *   QUERY in the format li <= ri, inclusive segment from li to ri
 *        : How long is the longest valid bracket subsequence in substring li, ri?
 *
 * ANSWER IDEA:
 *   Say we have two segments of length 4, next to each other:
 *     )()(  ())(
 *     0123  4567
 *   Store 3 quantities for each group
 *     a = # unmatched open brackets
 *     b = # unmatched open brackets
 *     c = # matched brackets
 *   Here we have: Group1 = {1, 1, 2} Group2 = {1,1,2}
 *   To combine, greedily match open brackets from the left to open brackets on the right
 *     )()(())(
 *     abbcddce
 *   Queries will do the same.
 *
 *   To simplify, consider this "combine" step as "a+b" of the "trpl" struct
 */

struct trpl {
	int a, b, c;
	trpl() {a=0, b=0, c=0;}
	trpl(int d, int e, int f) : a(d), b(e), c(f) {}
	void set(int d, int e, int f) {a = d, b=e, c=f;}
	trpl operator+ (const trpl& o) const {
		int bst = min(a, o.b);
		return trpl(a-bst+o.a, b+o.b-bst, c+o.c+2*bst);
	}
};

struct segtree {
	vector<trpl> t;
	int n, h;
	segtree(string s) {
		h = sizeof(int)*8 - __builtin_clz(s.length()-1);
		n = 1<<h;
		t = vector<trpl>(n<<1);
		for(int i=0;i<s.length();++i)
			t[i+n].set(s.at(i) == '(', s.at(i) == ')', 0);
		for(int i=n-1;i>0;--i)
			t[i]=t[i<<1]+t[i<<1|1];
	}
	int query(int l, int r) {
		trpl lp, rp;
		for(l+=n, r+=n;l<r;l>>=1, r>>=1) {
			if(l%2) lp = lp + t[l++];
			if(r%2) rp = t[--r] + rp;
		}
		return (lp + rp).c;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	segtree st(s);
	int m, li, ri;
	cin >> m;
	for(int i=0;i<m;++i) {
		cin >> li >> ri;
		cout << st.query(li-1, ri) << nl;
	}
	return 0;
}