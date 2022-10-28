#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back
int pre[100005];
int t[400005];
int lazy[400005];

void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = pre[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = max(t[v*2] ,t[v*2+1]);
    }
}

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
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1000000000;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
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
	
	pre[0]=0;
	for(int i=1; i<n; i++){
		pre[i]=pre[i-1]+arr[i];
	}
	stack<pair<int, int>>st;
	int l[n];
	l[0]=0;
	st.push({arr[0], 0});
	for(int i=1; i<n; i++){
		while(!st.empty() && st.top().f<=arr[i]){
			st.pop();
		}
		if(st.empty()){
			l[i]=0;
			st.push({arr[i], i});
			continue;
		}
		l[i]=st.top().s+1;
		st.push({arr[i], i});
	}
	while(!st.empty()){
		st.pop();
	}
	int r[n];
	r[n-1]=n-1;
	st.push({arr[n-1], n-1});
	for(int i=n-2; i>=0; i--){
		while(!st.empty() && st.top().f<=arr[i]){
			st.pop();
		}
		if(st.empty()){
			r[i]=n-1;
			st.push({arr[i], i});
			continue;
		}
		r[i]=st.top().s-1;
		st.push({arr[i], i});
	}

	build(1, 0, n-1);
	
	int maxi=query(1, 0, n-1, 0, r[0]);
	for(int i=1; i<n; i++){
		update(1, 0, n-1, i, n-1, -arr[i]);
		update(1, 0, n-1, 0, i-1, arr[i-1]);
		maxi=max(maxi, query(1, 0, n-1, i, r[i])+query(1, 0, n-1, l[i], i));
	}
	cout<<maxi;
	return 0;
}