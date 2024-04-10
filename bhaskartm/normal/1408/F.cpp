#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'



vector<pair<int, int>>v;

void f(int l, int r){
	if(r-l==1){
		v.pb({l, r});
		return;
	}
	int mid=(l+r)/2;
	f(l, mid);
	f(mid+1, r);
	for(int i=l; i<=mid; i++){
		v.pb({i, r+l-i});
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	if(n<=2){
		cout<<0;
		return 0;
	}
	
	int ans=0;
	int nn=n;
	
	while(nn!=0){
		ans++;
		nn=nn/2;
	}
	
	ans--;
	f(1, (1<<ans));
	vector<pair<int, int>>v2;
	for(auto u:v){
		v2.pb(u);
	}
	for(auto u:v){
		v2.pb({u.f+(n-(1<<ans)), u.s+(n-(1<<ans))});
	}
	cout<<v2.size()<<endl;
	for(auto u:v2){
		cout<<u.f<<" "<<u.s<<endl;
	}
	return 0;
}