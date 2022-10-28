#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
int n, k;
int arr[300005];

int t[1200005];


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
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


bool f(int val){
	for(int i=0; i<1200005; i++){
		t[i]=0;
	}
	int pt=0;
	bool pos[n];
	for(int i=0; i<n; i++){
		pos[i]=0;
	}
	for(int i=0; i<n; i++){
		while(arr[i]-arr[pt]>val){
			pt++;
		}
		if(i-pt+1<k){
			continue;
		}
		if(pt==0){
			pos[i]=1;
			update(1, 0, n, i, 1);
			continue;
		}
		int vals=sum(1, 0, n, pt-1, i-k);
		if(vals>0){
			pos[i]=1;
			update(1, 0, n, i, 1);
		}
	}
	return pos[n-1];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int lo=0;
	int hi =1e9;
	int ans=1e9;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		bool b=f(mid);
		
		if(b){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans;
	return 0;
}