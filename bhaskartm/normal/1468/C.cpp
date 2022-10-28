#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int cur=0;
int val[500005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	set<pair<int, int>>se;
	set<int>se2;
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			cur++;
			int x;
			cin>>x;
			se.insert({-x, cur});
			se2.insert(cur);
			val[cur]=x;
		}
		else if(t==2){
			auto it=se2.begin();
			int ind=(*it);
			cout<<ind<<" ";
			se2.erase(ind);
			se.erase({-val[ind], ind});
		}
		else{
			auto it=se.begin();
			int ind=(*it).s;
			se.erase(it);
			se2.erase(ind);
			cout<<ind<<" ";
		}
	}
	return 0;
}