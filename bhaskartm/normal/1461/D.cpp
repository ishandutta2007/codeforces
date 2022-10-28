#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const int N=1e5+5;
vector<int>v;
int pre[N];
map<int, int>m;

void f(int l, int r){
	if(l>r){
		return;
	}
	if(l==r){
		m[v[l]]=1;
		return;
	}
	if(v[l]==v[r]){
		m[pre[r]-pre[l-1]]=1;
		return;
	}
	m[pre[r]-pre[l-1]]=1;
	int ind=upper_bound(v.begin(), v.end(), (v[r]+v[l])/2)-v.begin();
	ind--;
	f(l, ind);
	f(ind+1, r);
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	
	while(t--){
		int n, q;
		cin>>n>>q;
		v.clear();
		m.clear();
		v.pb(0);
		for(int i=1; i<=n; i++){
			int x;
			cin>>x;
			v.pb(x);
		}
		sort(v.begin(), v.end());
		pre[0]=0;
		for(int i=1; i<=n; i++){
			pre[i]=pre[i-1]+v[i];
		}
		f(1, n);
		while(q--){
			int x;
			cin>>x;
			if(m[x]){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
	}
	
	return 0;
}