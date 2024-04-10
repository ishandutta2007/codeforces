#include <bits/stdc++.h>
using namespace std;

#define int long long int
int t[1200005];
int lazy[1200005];

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
        return -1e18;
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
	int p[n];
	int pos[n+1];
	for(int i=0; i<n; i++){
		cin>>p[i];
		pos[p[i]]=i;
	}
	int q[n];
	for(int i=0; i<n; i++){
		cin>>q[i];
	}
	int ans[n];
	ans[0]=n;
	update(1, 0, n-1, 0, pos[n], 1);
	int curr=n;
	for(int i=0; i<n-1; i++){
		
		int position=q[i]-1;
		update(1, 0, n-1, 0, position, -1);
		
		while(1){
			int num=query(1, 0, n-1, 0, n-1);
			if(num>0){
				break;
			}
			curr--;
			update(1, 0, n-1, 0, pos[curr], 1);
		}
		
		ans[i+1]=curr;
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}