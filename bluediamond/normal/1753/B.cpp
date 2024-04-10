#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int n,x;
	cin>>n>>x;
	vector<int>f((int)1e6,0);
	for (int i=1;i<=n;i++){
	int x;
	cin>>x;
	f[x]++;
	}
	
	for (int i=0;i<x;i++){
		if(f[i]%(i+1)!=0){
			cout<<"No\n";
			exit(0);
		}
		f[i+1]+=f[i]/(i+1);
	}
	cout<<"Yes\n";
	
	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */