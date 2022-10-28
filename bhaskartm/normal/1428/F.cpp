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
	int n;
	cin>>n;
	string st;
	cin>>st;
	vector<pair<int, int>>vec;
	for(int i=0; i<st.size(); i++){
		if(vec.empty() || vec.back().f!=(st[i]-'0')){
			vec.pb({st[i]-'0', 1});
		}
		else{
			auto u=vec.back();
			vec.pop_back();
			vec.pb({st[i]-'0', u.s+1});
		}
	}
	int ans=0;
	int tot=0;
	vector<int>las;
	int pt=0;
	
	for(auto u:vec){
		if(u.f==0){
			tot+=((u.s)*ans);
			pt+=u.s;
			
		}
		else{
			int num=u.s;
			int sz=las.size();
			int pt2=sz-1;
			for(int i=0; i<u.s; i++){
				if(pt2<0){
					ans+=(pt+1);
					tot+=ans;
					pt2--;
					pt++;
					
					continue;
				}
				ans+=(pt-las[pt2]);
				
				tot+=ans;
				pt2--;
				pt++;
			}
			int val2=las.size();
			if(u.s>=val2){
				while(!las.empty()){
					las.pop_back();
				}
				for(int i=pt-u.s; i<=pt-1; i++){
					las.pb(i);
				}
			}
			else{
				vector<int>temp;
				for(int i=0; i<u.s; i++){
					temp.pb(las.back());
					
					las.pop_back();
				}
				for(int i=pt-u.s; i<=pt-1; i++){
					
					las.pb(i);
				}
			}
		}
	}
	cout<<tot;
	return 0;
}