#include <bits/stdc++.h>

//asdf
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/** 
 * 501D Misha _ Permutations Summation
 *
 * PROBLEM:
 * Given a string 0,1,2,3...,n-1, order its permutations lexicographically..
 *   012, 021, 102, 120, 201, 210.  Number these, 0 to 5. (0 to n!)
 *   Perm(n) = the nth permutation
 *   Ord(a) = index of permutation that = array a
 * Now, if p and q are arrays which are permutations of 0...n-1, then
 *   define sum(p, q) = Perm((Ord(p)+Ord(q))%n!)
 * Given N, and two permutations p and q, find sum
 *   
 * SOLUTION:
 * 
 * Note that n! = 1 + sum_{i=1}^{n-1} i*i!.
 * We can store the permutation number as such:
 *   For length n, store n-1 numbers, as seen in the example with n = 5
 *     permutation:  3 2 4 0 1
 *     num storage: <3,2,2,0>
 *  -"Num storage": b[i]: "at position i, there are b[i] digits following
 *     which have a[j]<a[i] and j>i.
 *  -Flip num storage around: <0,2,2,3>
 *   Now the number = sum_{i=0}^{n-1}, b[i]*(i+1)!
 *  -This can be generated with a segtree
 *  -If at position i, b[i] >= (n+2)!, then mod by n+2 and divide the 
 *   excess over to the next position.
 *
 * SEGTREE TYPE:
 *   Segtree should just have range queries, point updates, sum.
 * 
 * ANSWER CONSTRUCTION:
 *   From left digit to right digit.
 *   If value is v, then choose the vth largest.
 *   Segtree with point updates, range queries, a find fn
 *     which binary searches for lower bound
 */

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline void read(int& x) {
	static char c;x=0;int sgn=1;
	for(c=get();c<'0' || c>'9';c=get()) if(c=='-') sgn=-1;
	for(;c>='0' && c<='9';c=get()) x=c-'0'+x*10;
	x*=sgn;
}

struct segtree {
	vector<int> t;
	int n,h;
	segtree(int sz){
		h=sizeof(int)*8-__builtin_clz(sz-1);
		n=1<<h;
		t=vector<int>(n<<1, 0);
	}
	segtree(int sz, bool f) {
		h=sizeof(int)*8-__builtin_clz(sz-1);
		n=1<<h;
		t=vector<int>(n<<1, 0);
		for(int i=0;i<sz;++i)
			t[i+n] = 1;
		for(int i=n-1;i>0;--i)
			t[i] = t[i<<1]+t[i<<1|1];
		
	}
	void add(int i, int v) {
		for(i+=n;i>0;i/=2) t[i] +=v;
	}
	int query(int l, int r) {
		int v = 0;
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
			if(l%2) { v+=t[l++]; }
			if(r%2) {v+=t[--r]; }
		}
		return v;
	}
	int find(int v) {
		int s = 1;
		int base = 0;
		while(s < n) {
			s *= 2;
			if(t[s]+base <= v)
				base += t[s++];
		}
		return s-n;
	}
};


void fillNum(vector<int>& p, vector<int>& nump, segtree& st, const int N) {
	st.add(p[N-1], 1);
	for(int i=0;i<N-1;++i) {
		nump[i] = st.query(0, p[N-2-i]);
		st.add(p[N-2-i], 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N;
	read(N);
	vector<int> p(N), q(N), nump(N, 0), numq(N, 0);
	for(int &ii:p) read(ii);
	for(int &ii:q) read(ii);

	segtree ps(N), qs(N), resurrect(N, true);
	fillNum(p, nump, ps, N);
	fillNum(q, numq, qs, N);
	int rem = 0;
	for(int i=0;i<N-1;++i) {
		nump[i] += rem + numq[i];
		rem = nump[i]/(i+2);
		nump[i]%=(i+2);
	}

	
	for(int i=N-2;i>=0;--i) {
		int v = resurrect.find(nump[i]);
		cout << v << " ";
		resurrect.add(v, -1);
	}
	cout << resurrect.find(0) << endl;

	
	return 0;
}