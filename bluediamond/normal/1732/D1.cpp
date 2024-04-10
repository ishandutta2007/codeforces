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

map<ll,ll>mex;
set<ll>st;

int tt;
cin>>tt;
	while(tt--){	
		string s;
		cin>>s;
		assert(s=="+"||s=="?");
		ll x;
		cin>>x;
		if(s=="+"){
			st.insert(x);
		}else{
		if(!mex.count(x))mex[x]=x;
			while(st.count(mex[x]))mex[x]+=x;
			cout<<mex[x]<<"\n";
		}
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