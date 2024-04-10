#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin>>n>>q;
	int a[n];
	set<int>se;
	multiset<int>dif;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
		se.insert(a[i]);
	}
	
	sort(a, a+n);
	
	for(int i=0; i+1<n; i++){
		dif.insert(a[i+1]-a[i]);
	}
	
	if(n<=2){
		cout<<0<<endl;
	}
	else{
		auto it=dif.end();
		it--;
		int val=(*it);
		auto it1=se.begin();
		auto it2=se.end();
		it2--;
		int val1=(*it1);
		int val2=(*it2);
		cout<<val2-val1-val<<endl;
	}
	int iter=0;
	while(q--){
		iter++;
		int t, x;
		cin>>t>>x;
		if(t==1){
			if(se.empty()){
				se.insert(x);
			}
			else if(se.lower_bound(x)==se.end()){
				auto it=se.end();
				it--;
				int val=(*it);
				dif.insert(x-val);
				se.insert(x);
			}
			else if(se.lower_bound(x)==se.begin()){
				auto it=se.begin();
				int val=(*it);
				dif.insert(val-x);
				se.insert(x);
			}
			else{
				auto it=se.lower_bound(x);
				auto it2=it;
				it2--;
				int val1=(*it2);
				int val2=(*it);
				se.insert(x);
				dif.insert(val2-x);
				dif.insert(x-val1);
				dif.erase(dif.find(val2-val1));
			}
		}
		else{
			auto it=se.end();
			it--;
			int maxi=(*it);
			if(se.size()<=1){
				se.erase(x);
				
			}
			else if(se.find(x)==se.begin()){
				auto it=se.begin();
				it++;
				int val=(*it);
				dif.erase(dif.find(val-x));
				se.erase(x);
			}
			else if(x==maxi){
				auto it=se.end();
				it--;
				it--;
				int val=(*it);
				dif.erase(dif.find(x-val));
				se.erase(x);
			}
			else{
				auto it=se.find(x);
				auto it1=it;
				auto it2=it;
				it1++;
				it2--;
				int val1=(*it1);
				int val2=(*it2);
				dif.insert(val1-val2);
				dif.erase(dif.find(x-val2));
				dif.erase(dif.find(val1-x));
				se.erase(x);
			}
		}
		if(se.size()<=2){
			cout<<0<<endl;
			continue;
		}
		auto it1=se.end();
		it1--;
		int maxi=(*it1);
		auto it2=se.begin();
		int mini=(*it2);
		auto it3=dif.end();
		it3--;
		cout<<maxi-mini-(*it3)<<endl;
		
	}

	return 0;
}