#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
int a[200005];
int t[800005];

const int MOD = 998244353;





void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v]= min(t[v*2] , t[v*2+1]);
    }
}

int mini(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 10000000000;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(mini(v*2, tl, tm, l, min(r, tm)), mini(v*2+1, tm+1, tr, max(l, tm+1), r));
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	
	int b[m];
	map<int, int>ma;
	for(int i=0; i<n; i++){
		cin>>a[i];
		ma[a[i]]=i;
	}
	for(int i=0; i<m; i++){
		cin>>b[i];
	}
	build(1, 0, n-1);
	bool booly=1;
	for(int i=0; i<m; i++){
		if(ma[b[i]]==0 && a[0]!=b[i]){
			booly=0;
		}
	}
	if(booly==0){
		cout<<0;
		return 0;
	}
	if(mini(1, 0, n-1, ma[b[m-1]], n-1)<b[m-1]){
		cout<<0;
		return 0;
	}
	int l[n];
	stack<pair<int, int>>st;
	for(int i=0; i<n; i++){
		while(!st.empty() && st.top().f>=a[i]){
			st.pop();
		}
		if(st.empty()){
			l[i]=-1;
		}
		else{
			l[i]=st.top().s;
		}
		st.push({a[i], i});
	}
	
	int last=0;
	int ans=1;
	for(int i=1; i<m; i++){
		int pos=ma[b[i]];
		if(pos<last){
			cout<<0;
			return 0;
		}
		if(pos==0 && a[0]!=b[i]){
			cout<<0;
			return 0;
		}
		int lpos=l[pos];
		if(lpos==-1){
			cout<<0;
			return 0;
		}
		ans=((ans)*(pos-lpos))%MOD;
		
		if(mini(1, 0, n-1, last, lpos)<b[i-1]){
			cout<<0;
			return 0;
		}
		last=pos;
	}
	cout<<ans;
	return 0;
}