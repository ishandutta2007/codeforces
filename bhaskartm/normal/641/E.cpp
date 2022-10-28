#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
vector<vector<int>>t;
vector<vector<int>>times;

int sum(int v, int tl, int tr, int l, int r, int i) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[i][v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm), i)
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r, i);
}

void update(int v, int tl, int tr, int pos, int new_val, int i) {
    if (tl == tr) {
        t[i][v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val, i);
        else
            update(v*2+1, tm+1, tr, pos, new_val, i);
        t[i][v] = t[i][v*2] + t[i][v*2+1];
    }
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int, pair<int, int>>>v;
	set<int>se;
	for(int i=0; i<n; i++){
		int a, t, x;
		cin>>a>>t>>x;
		se.insert(x);
		v.pb({a, {t, x}});
	}
	map<int, int>m;
	int pointer=0;
	for(auto it=se.begin(); it!=se.end(); it++){
		m[((*it))]=pointer;
		pointer++;
	}
	t.resize(pointer);
	times.resize(pointer);
	for(auto u:v){
		int val=m[u.s.s];
		times[val].pb(u.s.f);
	}
	for(int i=0; i<pointer; i++){
		sort(times[i].begin(), times[i].end());
	}
	map<int, int>ma[pointer];
	for(int i=0; i<pointer; i++){
		int pt=0;
		for(int j=0; j<times[i].size(); j++){
			ma[i][times[i][j]]=pt;
			pt++;
		}
	}
	for(int i=0; i<pointer; i++){
		t[i].resize((4*times[i].size())+20);
	}
	for(auto u:v){
		if(u.f==1){
			int num=m[u.s.s];
			int ind=ma[num][u.s.f];
			update(1, 0, times[num].size()-1, ind, 1, num);
		}
		else if(u.f==2){
			int num=m[u.s.s];
			int ind=ma[num][u.s.f];
			update(1, 0, times[num].size()-1, ind, -1, num);
		}
		else{
			int num=m[u.s.s];
			int ind=ma[num][u.s.f];
			cout<<sum(1, 0, times[num].size()-1, 0, ind, num)<<endl;
		}
	}
	return 0;
}