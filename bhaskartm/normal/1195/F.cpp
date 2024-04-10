#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;
map<pair<int, int>, vector<int>>ma;

int t[4*N+5];


int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		vector<pair<int, int>>vec;
		for(int j=0; j<k; j++){
			int x, y;
			cin>>x>>y;
			vec.pb({x, y});
		}
		for(int j=0; j<vec.size(); j++){
			int xx=vec[j].f-vec[(j+1)%vec.size()].f;
			int yy=vec[j].s-vec[(j+1)%vec.size()].s;
			if(xx==0){
				if(yy>0){
					ma[{0, 1}].pb(i);
				}
				else{
					ma[{0, -1}].pb(i);
				}
			}
			else if(yy==0){
				if(xx>0){
					ma[{1, 0}].pb(i);
				}
				else{
					ma[{-1, 0}].pb(i);
				}
			}
			else{
				int gc=__gcd(abs(xx), abs(yy));
				xx=xx/gc;
				yy=yy/gc;
				ma[{xx, yy}].pb(i);
			}
		}
	}

	int q;
	cin>>q;
	int ans[q];
	vector<vector<pair<int, int>>>qu;
	qu.resize(n);
	for(int i=0; i<q; i++){
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		qu[r].pb({l, i});
	}

	vector<vector<int>>add;
	add.resize(n);

	for(auto it=ma.begin(); it!=ma.end(); it++){
		vector<int>vecs=(it->second);
		for(int j=0; j<vecs.size(); j++){
			if(j==0){
				add[vecs[j]].pb(-1);
			}
			else{
				add[vecs[j]].pb(vecs[j-1]);
			}
		}
	}

	for(int i=0; i<n; i++){
		for(auto u:add[i]){
			update(1, 0, N, i, 1);
			if(u!=-1){
				update(1, 0, N, u, -1);
			}
		}
		for(auto u:qu[i]){
			ans[u.s]=sum(1, 0, N, u.f, i);
		}
	}
	for(int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}