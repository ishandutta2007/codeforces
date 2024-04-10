#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
int t1[1200005];
const int N=1e9;
const int N1=1e15;
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
 
 
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t1[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t1[v] = t1[v*2] + t1[v*2+1];
    }
}
 
 
 
 
 
 
pair<int, int> t[1200005];
int lazy[1200005];
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {0, tl};
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}
 
void push(int v) {
    t[v*2].f += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].f += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
 
void update2(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].f += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update2(v*2, tl, tm, l, min(r, tm), addend);
        update2(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
 
pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {N, 0};
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
 
 
 
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin>>n>>q;
	int arr[n+1];
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	vector<vector<pair<int, int>>>qu;
	qu.resize(n+2);
	int ans[q];
	for(int i=0; i<q; i++){
		int x, y;
		cin>>x>>y;
		qu[x].pb({y, i});
	}
	int val[n];
	for(int i=1; i<=n; i++){
		if(arr[i]>i){
			val[i]=N1;
		}
		else{
			val[i]=i-arr[i];
		}
	}
	int cnt=0;
	int bef[n+1];
	
	for(int i=1; i<=n; i++){
		if(val[i]<=cnt){
			bef[i]=cnt;
			cnt++;
			continue;
		}
		else{
			bef[i]=cnt;
			val[i]=N1;
			continue;
		}
	}
	for(int i=1; i<=n; i++){
		if(val[i]<N){
			update(1, 1, n, i, 1);
		}
		else{
			update(1, 1, n, i, 0);
		}
	}
	build(1, 1, n);
	for(int i=1; i<=n; i++){
		if(val[i]<N){
			update2(1, 1, n, i, i, bef[i]-val[i]);
		}
		else{
			update2(1, 1, n, i, i, N);
		}
	}

	for(int i=0; i<n; i++){
	
		if(i!=0){
			if(val[i]>=N){
				
			}
			else{
				update2(1, 1, n, i+1, n, -1);
				update2(1, 1, n, i, i, N);
				update(1, 1, n, i, 0);
				val[i]=N1;
				while(1){
					auto mini=query(1, 1, n, 1, n);
					if(mini.f>=0){
						break;
					}
					int ind=mini.s;
				
					val[ind]=N1;
					update2(1, 1, n, ind+1, n, -1);
					update2(1, 1, n, ind, ind, N);
					update(1, 1, n, ind, 0);
					
				}
			}
		}
	
		for(auto u:qu[i]){
			ans[u.s]=sum(1, 1, n, i+1, n-u.f);
		}
	}
	for(int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}