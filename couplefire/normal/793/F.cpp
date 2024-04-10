#include <bits/stdc++.h>
using namespace std;

template<class T> struct Seg { 
	const T ID = -1; // comb(ID,b) must equal b, and maximum is less than 1e9
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

int n, m, q;
vector<int> leftEnd[100005];
vector<int> rightEnd[100005];
vector<pair<int, int>> queriesRight[100005];
int ans[100005];

void solve(int l, int r){
    if(l > r) return;
    int mid = (l+r)/2;
    if(l != r){
        solve(l, mid); solve(mid+1, r);
    }
    else{
        for(auto query : queriesRight[r]){
            if(query.first != r) continue;
            ans[query.second] = r;
        }
        return;
    }
    int dp[mid-l+1];
    Seg<int> sg1; sg1.init(mid-l+1);
    for(int i = mid; i>=l; i--){
        int indleft = upper_bound(leftEnd[i].begin(), leftEnd[i].end(), mid)-leftEnd[i].begin()-1;
        int val;
        if(indleft < 0) val = -1;
        else val = leftEnd[i][indleft];
        dp[i-l] = max(i, sg1.query(i-l, val-l));
        dp[i-l] = max(dp[i-l], val);
        sg1.upd(i-l, dp[i-l]);
    }
    vector<int> cur; 
    Seg<int> sg2; sg2.init(mid-l+1);
    for(int i = mid+1; i<=r; i++){
        if(rightEnd[i].size() > 0 && rightEnd[i][0] >= l){
            int num = rightEnd[i][0];
            if(num <= mid){
                sg2.upd(num-l, i);
            }
            else {
                while(cur.size() > 0 && cur.back() >= num){
                    cur.pop_back();
                }
            }
        }
        cur.push_back(i);
        for(auto query : queriesRight[i]){
            int x = query.first; int ind = query.second;
            if(x >= mid+1) continue;
            if(x < l) continue;
            int mxright = dp[x-l];
            int val = sg2.query(x-l, mxright-l);
            if(val == -1){
                ans[ind] = mxright;
                continue;
            }
            else val = sg2.query(x-l, mid-l);
            if(cur.empty()){
                ans[ind] = val;
                continue;
            }
            int bruh = min((int)(lower_bound(cur.begin(), cur.end(), val)-cur.begin()), (int)cur.size()-1);
            ans[ind] = max(cur[bruh], val);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        leftEnd[a].push_back(b);
        rightEnd[b].push_back(a);
    }
    for(int i = 0; i<100005; i++){
        sort(leftEnd[i].begin(), leftEnd[i].end());
        sort(rightEnd[i].begin(), rightEnd[i].end());
    }
    cin >> q;
    for(int i = 0; i<q; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        queriesRight[b].push_back({a, i});
        // cout << brute(a, b)+1 << endl;
    }
    solve(0, n-1);
    for(int i = 0; i<q; i++) cout << ans[i]+1 << endl;
}