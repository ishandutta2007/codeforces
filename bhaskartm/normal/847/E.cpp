#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

vector<int>pac;
vector<int>v;



bool f(int tim){
	int pt=0;
	
	for(int i=0; i<pac.size(); i++){
		if(pt==v.size()){
			return 1;
		}
		
		if(v[pt]>pac[i]){
			while(pt<v.size() && v[pt]<=pac[i]+tim){
				pt++;
			}
			if(pt==v.size()){
				return 1;
			}
			continue;
		}
		if(pac[i]-v[pt]>tim){
			return 0;
		}
		int pt1=pt;
		int fo=tim-2*(pac[i]-v[pt]);
		if(fo<=0){
			while(pt1<v.size() && v[pt1]<=pac[i]){
				pt1++;
			}
		}
		else{
			while(pt1<v.size() && v[pt1]<=pac[i]+fo){
				pt1++;
			}
		}
		
		int pt2;
		pt2=pt;
		fo=(tim-(pac[i]-v[pt]))/2;
		if(fo<0){
			pt2=0;
		}
		else{
			while(pt2<v.size() && v[pt2]<=pac[i]+fo){
				pt2++;
			}
		}
		
		pt=max(pt1, pt2);
		
		if(pt==v.size()){
			return 1;
		}
	}
	return 0;
}




main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string st;
	cin>>st;
	
	for(int i=0; i<st.size(); i++){
		if(st[i]=='P'){
			pac.pb(i);
		}
		if(st[i]=='*'){
			v.pb(i);
		}
	}
	
	int lo=0;
	int hi=3e5;
	int ans=3e5;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		bool b=f(mid);
		
		if(b){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans;
	
	
	return 0;
}