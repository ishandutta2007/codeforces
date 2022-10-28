#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const int N=1000000;

int t[4000010];

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
	int n, m;
	cin>>n>>m;
	int ans=1;
	vector<pair<pair<int, int>, pair<int, int>>>v;
	for(int i=0; i<n; i++){
		int y, l, r;
		cin>>y>>l>>r;
		if(l==0 && r==N){
			ans++;
		}
		v.pb({{l, -1}, {y, 0}});
		v.pb({{r, 1}, {y, 0}});
	}
	for(int i=0; i<m; i++){
		int x, y1, y2;
		cin>>x>>y1>>y2;
		v.pb({{x, 0}, {y1, y2}});
		if(y1==0 && y2==N){
			ans++;
		}
	}

	sort(v.begin(), v.end());
	for(auto u:v){
		if(u.f.s==-1){
			update(1, 0, 1000000, u.s.f, 1);
			continue;
		}
		if(u.f.s==1){
			update(1, 0, 1000000, u.s.f, -1);
			continue;
		}
		
		ans+=sum(1, 0, 1000000, u.s.f, u.s.s);
		
	}
	cout<<ans;
	return 0;
}