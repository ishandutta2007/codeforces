#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define F0R(i, a) for (int i=0; i<a; i++)
#define pb push_back
#define f first
#define s second

const int MOD = 1000000007;
const int SZ = 100000;

int N,K,Q,segmin[4*SZ],seg[8*SZ], lazy[8*SZ];
unordered_map<int,int> key;
vector<int> tot;
vector<pair<pii,pii>> q;

int qmin(int l, int r) {  
	if (r-l >= N) l = 0, r = N;
	else {
		l %= N, r %= N;
		if (r < l) r += N;
	}
	int res = MOD;
	for (l += 2*SZ, r += 2*SZ; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res,segmin[l++]);
	    if (r&1) res = min(res,segmin[--r]);
	}
	return res;
}

void push(int ind, int low, int high) {
	if (lazy[ind] != MOD) {
		seg[ind] = lazy[ind];
	    if (low != high) lazy[2*ind] = lazy[ind], lazy[2*ind+1] = lazy[ind];
	    lazy[ind] = MOD;
	}
}

int qmin1(int ind, int low, int high, int L, int R) {
	push(ind,low,high);
    if (low > R || high < L) return MOD;
    if (L <= low && high <= R) return seg[ind];
    return min(qmin1(2*ind,low,(low+high)/2,L,R),qmin1(2*ind+1,(low+high)/2+1,high,L,R));
}

void modifymin1(int ind, int low, int high, int L, int R, int val) { 
    push(ind,low,high);
    if (high < L || R < low) return;
    if (L <= low && high <= R) {
        seg[ind] = val;
        if (low != high) lazy[2*ind] = val, lazy[2*ind+1] = val;
        return;
    }
    modifymin1(2*ind,low,(low+high)/2,L,R,val);
    modifymin1(2*ind+1,(low+high)/2+1,high,L,R,val);
    seg[ind] = min(seg[2*ind],seg[2*ind+1]);
}

int main() {
	F0R(i,4*SZ) lazy[i] = MOD;
	cin >> N >> K;
	F0R(i,N) {
		int x; cin >> x;
		segmin[i+2*SZ] = segmin[i+2*SZ+N] = x;
	}
	for (int i = 2*SZ-1; i > 0; --i) segmin[i] = min(segmin[2*i],segmin[2*i+1]);
	tot.pb(N*K);
	cin >> Q;
	F0R(i,Q) {
		int t,l,r,x; cin >> t >> l >> r;
		l--, r--;
		if (t == 1) cin >> x;
		q.pb({{t,x},{l,r}});
		tot.pb(l); tot.pb(r+1);
	}
	sort(tot.begin(), tot.end());
	tot.erase(unique(tot.begin(), tot.end()), tot.end());
	F0R(i,tot.size()) {
	    key[tot[i]] = i;
	    if (i != tot.size()-1) modifymin1(1,0,2*SZ-1,i,i+1,qmin(tot[i],tot[i+1]));
	}
	for (auto a: q) {
		if (a.f.f == 1) modifymin1(1,0,2*SZ-1,key[a.s.f],key[a.s.s+1]-1,a.f.s);
		else cout << qmin1(1,0,2*SZ-1,key[a.s.f],key[a.s.s+1]-1) << "\n";
	}
}