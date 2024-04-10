#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
int t[2400005];
int lazy[2400005];


void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1000000000;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	set<int>s;
	map<int, int>m;
	vector<pair<pair<int, int>, int>>v;
	for(int i=1; i<=n; i++){
		int l, r;
		cin>>l>>r;
		s.insert(l);
		s.insert(r);
		
		s.insert(l-1);
		v.pb({{l, r}, i});
	}
	int pointer=-1;
	for(auto it=s.begin(); it!=s.end(); it++){
		pointer++;
		m[(*it)]=pointer;
	}
	
	for(int i=0; i<v.size(); i++){
		v[i].f.f=m[v[i].f.f];
		v[i].f.s=m[v[i].f.s];
	}
	
	for(auto u:v){
		update(1, 0, pointer, u.f.f, u.f.s, 1);
	}
	
	for(auto u:v){
		
		int val=query(1, 0, pointer, u.f.f, u.f.s);
		if(val>1){
			cout<<u.s;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}