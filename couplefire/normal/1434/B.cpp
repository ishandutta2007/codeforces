#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

template<class T> struct Seg { 
	const T ID = 0; // comb(ID,b) must equal b, and minimum is greater than -1e9
	T comb(T a, T b) { return max(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.resize(2*n); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

Seg<int> seg;
int n;
int ans[2*MAXN] = {0};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    seg.init(MAXN);
    set<int> pos;
    for(int i = 1; i<=2*n; i++){
        char c; cin >> c;
        if(c == '+'){
            pos.insert(i);
        }
        else{
            int num; cin >> num;
            int mapos = seg.query(num+1, n);
            auto it = pos.lower_bound(mapos);
            if(it == pos.end()){
                cout << "NO" << endl;
                exit(0);
            }
            ans[(*it)] = num;
            pos.erase(it);
            seg.upd(num, i);
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i<2*MAXN; i++){
        if(ans[i] != 0) cout << ans[i] << " ";
    }
    cout << endl;
}