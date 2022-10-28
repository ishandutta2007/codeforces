#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n+1];
	int l[n+1];
	int r[n+1];
	int ans=0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		l[i]=i-1;
		r[i]=i+1;
	}
	set<pair<int, int>>se;
	for(int i=1; i<=n; i++){
		se.insert({arr[i], i});
	}
	int dec=0;
	while(!se.empty()){
		if(se.size()<=2){
			cout<<ans;
			return 0;
		}
		auto it=se.begin();
		int val=(*it).f;
		int pos=(*it).s;
		ans+=(se.size()-2)*(val-dec);
		dec=val;
		se.erase((*it));
		if(l[pos]==0){
			l[r[pos]]=0;
			continue;
		}
		if(r[pos]==n+1){
			r[l[pos]]=n+1;
			continue;
		}
		ans+=(min(arr[l[pos]], arr[r[pos]])-dec);
		r[l[pos]]=r[pos];
		l[r[pos]]=l[pos];
	}
	cout<<ans;
	return 0;
}