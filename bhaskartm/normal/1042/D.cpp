#include <bits/stdc++.h>
using namespace std;
#define int long long int
int t[2400005];
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
	int n, t;
	cin>>n>>t;
	set<int>s;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+arr[i-1];
	}
	
	for(int i=0; i<=n; i++){
		s.insert(pre[i]);
		
		s.insert(pre[i]-t+1);
	}
	map<int, int>m;
	int pt=0;
	for(auto it=s.begin(); it!=s.end(); it++){
		m[(*it)]=pt;
		
		pt++;
	}
	int pre2[n+1];
	for(int i=0; i<=n; i++){
		pre2[i]=m[pre[i]];
	}
	pt--;
	
	update(1, 0, pt, pre2[0], 1);
	
	int ans=0;
	for(int i=1; i<=n; i++){
		if(t>=0){
			
			ans+=sum(1 ,0, pt, m[pre[i]-t+1], pt);
		}
		else{
			ans+=sum(1, 0, pt, m[pre[i]-t+1], pt);
		}
		update(1, 0, pt, m[pre[i]], 1);
	}
	cout<<ans;
	return 0;
}