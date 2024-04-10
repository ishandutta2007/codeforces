#include <bits/stdc++.h>
using namespace std;
#define int long long int
int t[1600005];
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
        t[v]=max(t[v*2], t[v*2+1]);
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
	for(int i=0; i<n; i++){
		arr[i]=arr[i]-i;
	}
	set<int>s;
	for(int i=0; i<n; i++){
		s.insert(arr[i]);
		s.insert(arr[i]+1);
	}
	map<int, int>m;
	int pointer=0;
	for(auto it=s.begin(); it!=s.end(); it++){
		m[(*it)]=pointer;
		pointer++;
	}
	int maxim=0;
	for(int i=0; i<n; i++){
		arr[i]=m[arr[i]];
		maxim=max(maxim, arr[i]);
	}
	
	int fr[n];
	int ba[n];
	fr[0]=1;
	ba[n-1]=1;
	
	for(int i=0; i<n; i++){
		
		fr[i]=1+maxi(1, 0, maxim, 0, arr[i]);
		
		update(1, 0, maxim, arr[i], fr[i]);
		
	}
	
	for(int i=0; i<1600005; i++){
		t[i]=0;
	}
	
	for(int i=n-1; i>=0; i--){
		ba[i]=1+maxi(1, 0, maxim, arr[i], maxim);
		
		update(1, 0, maxim, arr[i], ba[i]);
		
	}
	
	for(int i=0; i<1600005; i++){
		t[i]=0;
	}
	int maximi=0;
	for(int i=1; i<n; i++){
		maximi=max(maximi, ba[i]);
	}
	int maximi2=0;
	for(int i=0; i<n-1; i++){
		maximi2=max(maximi2, fr[i]);
	}
	int ans=n-1-maximi;
	ans=min(ans, n-1-maximi2);
	int def=0;
	
	for(int i=n-2; i>0; i--){
		
		update(1, 0, maxim, arr[i+1], ba[i+1]);
		
		int val=maxi(1, 0, maxim, max(def, arr[i-1]-1), maxim);
		
		ans=min(ans, n-1-val-fr[i-1]);
		
	}
	
	cout<<ans;
	return 0;
}