#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

vector<vector<int>>ri;
vector<vector<int>>q;
vector<pair<int, int>>segs;
int t[4000005];
map<pair<int, int>, int>ma;
vector<vector<int>>points;
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	ri.resize(1000005);
	points.resize(1000005);
	for(int i=0; i<n; i++){
		int l, r;
		cin>>l>>r;
		ri[r].pb(l);
	}
	q.resize(m);
	for(int i=0; i<m; i++){
		int cnt;
		cin>>cnt;
		q[i].pb(0);
		for(int j=0; j<cnt; j++){
			int val;
			cin>>val;
			q[i].pb(val);
		}
		q[i].pb(1000001);
		for(int j=0; j<q[i].size()-1; j++){
			segs.pb({q[i][j], q[i][j+1]});
		}
	}
	for(auto u:segs){
		points[u.s].pb(u.f);
	}
	int num=0;
	for(int i=2; i<1000005; i++){
		for(auto u:ri[i-1]){
			num++;
			update(1, 0, 1000001, u, 1);
		}
		for(auto u:points[i]){
			int val=num-sum(1, 0, 1000001, 0, u);
			ma[{u, i}]=val;
		}
	}
	for(int i=0; i<q.size(); i++){
		int sum=0;
		for(int j=0; j<q[i].size()-1; j++){
			sum+=ma[{q[i][j], q[i][j+1]}];
		}
		cout<<n-sum<<endl;
	}
	return 0;
}