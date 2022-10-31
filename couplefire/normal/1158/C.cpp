#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;
vector<int> in;

template<class T> struct Seg { 
	const T ID = -1e9; // comb(ID,b) must equal b, and minimum is greater than -1e9
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

bool toposort(int n){
    queue<int> todo;
    for(int i = 0; i<n; i++) if(!in[i]) todo.push(i);
    while(todo.size()){
        int x = todo.front();
        todo.pop();
        ans.push_back(x);
        for(auto i : adj[x]) if(!(--in[i])) todo.push(i);
    }
    return ans.size() == n;
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while(q--){
        adj.clear();
        ans.clear();
        in.clear();
        int n; cin >> n;
        int p[n];
        adj.resize(n);
        in.assign(n, 0);
        for(int i = 0; i<n; i++){
            cin >> p[i];
            --p[i];
        }
        Seg<int> s;
        s.init(n+2);
        for(int i = 0; i<n; i++){
            int re = s.query(i+1, n+1);
            //cout << re-1 << endl;
            if(re > 0){
                adj[i].push_back(re-1);
                in[re-1]++;
            }
            if(p[i] != -2) s.upd(p[i], i+1);
        }
        //cout << s.query(7, 7) << endl;
        for(int i = 0; i<n; i++){
            if(p[i] < 0) continue;
            if(p[i] < n){
                adj[i].push_back(p[i]);
                in[p[i]]++;
            }
        }
        // for(int i = 0;  i<n; i++){
        //     cout << i+1 << endl;
        //     for(auto k : adj[i]) cout << k+1 << " ";
        //     cout << endl << endl;
        // }
        if(!toposort(n)){
            cout << -1 << endl;
            continue;
        }
        int res[n];
        for(int i = 0; i<n; i++){
            res[ans[i]] = i+1;
        }
        for(int i = 0; i<n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}