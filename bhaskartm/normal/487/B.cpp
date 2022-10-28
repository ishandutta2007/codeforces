#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define pb push_back

int dp[100005];
int t[400005];


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}

int mini(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1000000000;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(mini(v*2, tl, tm, l, min(r, tm)),mini(v*2+1, tm+1, tr, max(l, tm+1), r));
}

 main() {
 	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s, l;
	cin>>n>>s>>l;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	multiset<int>se;
	int lb[n];
	lb[0]=0;
	int r=0;
	if(l==1){
		cout<<n;
		return 0;
	}
	se.insert(arr[0]);
	for(int i=1; i<n; i++){
	
		se.insert(arr[i]);
		while(1){
			auto it=se.begin();
			int mini=(*it);
			auto it2=se.end();
			it2--;
			int maxi=(*it2);
			if(maxi-mini<=s){
				break;
			}
			else{
				se.erase(se.find(arr[r]));
				r++;
			}
		}
		lb[i]=r;
	}
	
	if(l==1){
		dp[0]=1;
		update(1, 0, n-1, 0, 1);
	}
	else{
		dp[0]=1000000000;
		update(1, 0, n-1, 0, 1000000000);
	}
	
	for(int i=1; i<n; i++){
		if(i+1<l){
			dp[i]=1000000000;
			update(1, 0, n-1, i, 1000000000);
			continue;
		}
		if(i==l-1){
			if(lb[i]==0){
				dp[i]=1;
				update(1, 0, n-1, i, 1);
			}
			else{
				dp[i]=1000000000;
				update(1, 0, n-1, i, 1000000000);
				
			}
			continue;
		}
		if(lb[i]>i-l+1){
			dp[i]=1000000000;
			update(1, 0, n-1, i, 1000000000);
			continue;
		}
		else{
			if(lb[i]==0){
				dp[i]=1;
				update(1, 0, n-1, i, 1);
				continue;
			}
			dp[i]=1+mini(1, 0, n-1, lb[i]-1, i-l);
			update(1, 0, n-1, i, dp[i]);
		}
	}
	if(dp[n-1]>=10000000){
		cout<<-1;
	}
	else{
		cout<<dp[n-1];
	}
	return 0;
}