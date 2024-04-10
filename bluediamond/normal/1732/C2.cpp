#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int B=30;

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif



int tt;
cin>>tt;
	for(int tc=1;tc<=tt;tc++){
		int n,q;
		cin>>n>>q;
		vector<int>a(n),nxt(n,-1),ant(n,-1);
		vector<ll> xo(n+1,0),su(n+1,0);
		for (int i=0;i<n;i++){
			cin>>a[i];
			xo[i+1]=xo[i]^a[i];
			su[i+1]=su[i]+a[i];
		}
		function<ll(int,int)>get=[&](int l,int r){
			if(l>r)return 0LL;
			assert(0<=l&&l<=r&&r<n);
			l++;
			r++;
			return (su[r]-su[l-1])-(xo[r]^xo[l-1]);
		};
		for(int i=0;i<n;i++){
			if(i!=0){
				if(a[i-1]!=0)ant[i]=i-1;else ant[i]=ant[i-1];
			}
		}
		for(int i=n-1;i>=0;i--){
			if(i!=n-1){
				if(a[i+1]!=0)nxt[i]=i+1;else nxt[i]=nxt[i+1];
			}
		}
		for (int iq=1;iq<=q;iq++){
			int l,r;
			cin>>l>>r;
			l--,r--;
			assert(0<=l&&l<=r&&r<n);
			ll src=get(l,r);
			if(src==0){
				cout<<l+1<<" "<<l+1<<"\n";
				continue;
			}
			assert(src>0);
			int i=l;
			while(nxt[i]<=r&&nxt[i]!=-1&&get(nxt[i],r)==src)i=nxt[i];
			int L=l,R=r;
			function<void(int,int)>upd=[&](int a,int b){
				assert(get(a,b)==src);
				if(b-a+1<R-L+1){
					L=a;
					R=b;
				}
			};
			int j=r;
			while(ant[j]>=i&&ant[j]!=-1&&get(i,ant[j])==src)j=ant[j];
			upd(i,j);
			while(ant[i]>=l&&ant[i]!=-1){
				i=ant[i];
				assert(get(i,j)==src);
				while(ant[j]>=i&&ant[j]!=-1&&get(i,ant[j])==src)j=ant[j];
				upd(i,j);
			}
			cout<<L+1<<" "<<R+1<<"\n";	
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