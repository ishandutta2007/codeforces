#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    vector<int> v;
    int pre, avg;
    node(){}
    bool operator < (const node& o) const{
        return avg<o.avg;
    }
};

template<class T> struct Seg { 
	const T ID = -1e9; // comb(ID,b) must equal b, and maximum is less than 1e9
	T comb(T a, T b) { return max(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // minimum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<node> brr(m);
    for(int i = 0; i<m; ++i){
        int k; cin >> k;
        brr[i].v.resize(k);
        ll tmp = 0;
        for(int j = 0; j<k; ++j)
            cin >> brr[i].v[j], tmp += brr[i].v[j];
        brr[i].avg = (tmp+k-1)/k;
        brr[i].pre = (i?brr[i-1].pre+brr[i-1].v.size():0);
    } int tot = brr.back().pre+brr.back().v.size();
    string ans(tot, '0');
    sort(brr.begin(), brr.end());
    Seg<int> seg; seg.init(m);
    for(int i = 0; i<m; ++i){
        int id = lower_bound(arr.begin(), arr.end(), brr[i].avg)-arr.begin();
        seg.upd(i, id-i);
    }
    for(int i = 0; i<m; ++i){
        ll sum = 0;
        for(auto x : brr[i].v)
            sum += x;
        for(int j = 0; j<(int)brr[i].v.size(); ++j){
            int navg = (sum-brr[i].v[j]+(int)brr[i].v.size()-2)/((int)brr[i].v.size()-1);
            node tmp; tmp.avg = navg;
            int id = lower_bound(brr.begin(), brr.end(), tmp)-brr.begin();
            if(id<=i){
                int mx1 = seg.query(i+1, m-1)+m-1;
                if(mx1>n-1) continue;
                int mx2 = seg.query(id, i-1)+i-1;
                if(mx2>n-1-(m-i-1)) continue;
                if(navg>arr[n-1-(m-id-1)]) continue;
                int mx3 = seg.query(0, id-1)+id-1;
                if(mx3>n-1-(m-id)) continue;
                ans[brr[i].pre+j] = '1';
            } else{
                int mx1 = seg.query(id, m-1)+m-1;
                if(mx1>n-1) continue;
                if(navg>arr[n-1-(m-id)]) continue;
                int mx2 = seg.query(i+1, id-1)+id-1;
                if(mx2>n-1-(m-id)-1) continue;
                int mx3 = seg.query(0, i-1)+i-1;
                if(mx3>n-1-(m-i)) continue;
                ans[brr[i].pre+j] = '1';
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}