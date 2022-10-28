#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long int
int t[1600005];

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

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	set<int>se;
	vector<pair<pair<int, int>, int>>v;
	for(int i=0; i<n; i++){
		int l, r;
		cin>>l>>r;
		v.pb({{r, l}, i});
		se.insert(l);
		se.insert(r);
	}
	map<int, int>m;
	int pointer=0;
	for(auto it=se.begin(); it!=se.end(); it++){
		m[(*it)]=pointer;
		pointer++;
	}
	for(int i=0; i<v.size(); i++){
		v[i].f.f=m[v[i].f.f];
		v[i].f.s=m[v[i].f.s];
	}
	int ans[n];
	
	sort(v.begin() ,v.end());
	
	for(auto u:v){
		int r=u.f.f;
		int l=u.f.s;
	
		ans[u.s]=sum(1, 0, 400001, l, r);
		update(1, 0, 400001, l, 1);
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}