#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int l[100005];
int r[100005];
bool ans[100005];
const int N=1e18;
int t[400005];


int mini(int v, int tl, int tr, int l, int r){
    if (l>r) 
        return N;
    if (l==tl && r==tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(mini(v*2, tl, tm, l, min(r, tm)),mini(v*2+1, tm+1, tr, max(l, tm+1), r));
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
        t[v] = min(t[v*2], t[v*2+1]);
    }
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int las[100005];
	for(int i=0; i<=n+1; i++){
		las[i]=-1;
	}
	for(int i=0; i<n; i++){
		l[i]=las[arr[i]+1]+1;
		las[arr[i]]=i;
	}
	for(int i=0; i<=n+1; i++){
		las[i]=n;
	}
	for(int i=n-1; i>=0; i--){
		r[i]=las[arr[i]+1]-1;
		las[arr[i]]=i;
	}
	
	vector<vector<pair<int, int>>>qu;
	qu.resize(n+1);
	
	for(int i=0; i<n; i++){
		qu[r[i]].pb({l[i], arr[i]});
		
	}
	
	for(int i=1; i<=n; i++){
		update(1, 0, n, i, -1);
	}
	
	for(int i=0; i<n; i++){
		update(1, 0, n, arr[i], i);
		for(auto u:qu[i]){
			int val=u.s;
			int l=u.f;
			int ind=mini(1, 0, n, 1, val);
			
			if(ind>=l){
				ans[val+1]=1;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		if(arr[i]!=1){
			ans[1]=1;
		}
	}
	if(ans[1]==0){
		cout<<1;
		return 0;
	}
	for(int i=1; i<=n+2; i++){
		if(!ans[i]){
			cout<<i;
			return 0;
		}
	}
	
	return 0;
}