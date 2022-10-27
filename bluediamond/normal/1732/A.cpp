#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


const int N=20+7;
int n,a[N],b[N],sol;

void expl(int i,int cost,int cur){
if(cost>=sol)return;
if(cur==1){
sol=cost;
	return;
}
if(i==n+1){
	return;
}
expl(i+1,cost+n+1-i,__gcd(cur,b[i]));
expl(i+1,cost,__gcd(cur,a[i]));
}

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int tt;
	cin>>tt;
	while(tt--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=__gcd(a[i],i);
		}
		sol=(int)1e9+7;
		expl(1,0,0);
		cout<<sol<<"\n";
	}
	
	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */