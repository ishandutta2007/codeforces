#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int M=-1e18;
const int N=3e5+5;
int n;
int h[N];
int b[N];
int t[4*N+5];
int dp[N];


int maxi(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -1e18;
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
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>h[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	stack<pair<int, int>>st;
	dp[0]=b[0];
	update(1, 0, N, 0, dp[0]);
	st.push({h[0], 0});
	for(int i=0; i<n; i++){
		while(!st.empty() && st.top().f>h[i]){
			st.pop();
		}
		if(st.empty()){
			dp[i]=max((maxi(1, 0, N, 0, i-1)+b[i]), b[i]);
			update(1, 0, N, i, dp[i]);
			st.push({h[i], i});
			continue;
		}
		int ind=st.top().s;
		st.push({h[i], i});
		int val1=maxi(1, 0, N, ind, i-1);
		dp[i]=max(dp[ind], val1+b[i]);
		update(1, 0, N, i, dp[i]);
	}
	cout<<dp[n-1];
	return 0;
}