#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int t[2000055];

int maxi(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(maxi(v*2, tl, tm, l, min(r, tm)), maxi(v*2+1, tm+1, tr, max(l, tm+1), r));
}


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	vector<int>v;
	v.pb(-1e18);
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		x=x-i;
		v.pb(x);
	}
	v.pb(1e18);
	vector<int>pr;
	pr.pb(0);
	for(int i=0; i<k; i++){
		int x;
		cin>>x;
		pr.pb(x);
	}
	pr.pb(n+1);
	for(int i=0; i<pr.size()-1; i++){
		if(v[pr[i+1]]<v[pr[i]]){
			cout<<-1;
			return 0;
		}
	}
	int ans=0;
	for(int i=0; i<pr.size()-1; i++){
		vector<int>temp;
		for(int j=pr[i]+1; j<=pr[i+1]-1; j++){
			if(v[j]>=v[pr[i]] && v[j]<=v[pr[i+1]]){
				temp.pb(v[j]);
			}
			else{
				ans++;
			}
		}
		if(temp.size()==0){
			continue;
		}
		
		map<int, int>ma;
		int pt=0;
		set<int>se;
		for(auto u:temp){
			se.insert(u);
		}
		for(auto u:se){
			ma[u]=pt;
			pt++;
		}
		for(int i=0; i<temp.size(); i++){
			temp[i]=ma[temp[i]];
		}
		
		int maxim=0;
		for(int i=0; i<temp.size(); i++){
			int val=maxi(1, 0, pt, 0, temp[i]);
			maxim=max(maxim, val+1);
			update(1, 0, pt, temp[i], val+1);
		}
		for(int i=0; i<4*pt+5; i++){
			t[i]=0;
		}
		ans+=(temp.size()-maxim);
	}
	cout<<ans<<endl;
	return 0;
}