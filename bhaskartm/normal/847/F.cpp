#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int cnt[105];
int la[105];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, m, a;
	cin>>n>>k>>m>>a;
	
	int arr[a];
	for(int i=0; i<n; i++){
		la[i]=1000;
	}
	for(int i=0; i<a; i++){
		cin>>arr[i];
		arr[i]--;
		cnt[arr[i]]++;
		la[arr[i]]=i;
	}
	vector<pair<pair<int, int>, int>>vec;
	for(int i=0; i<n; i++){
		vec.pb({{cnt[i], -la[i]}, i});
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int ans[n];
	for(int i=0; i<vec.size(); i++){
		int ind=vec[i].s;
		int cn=vec[i].f.f;
		int las=-vec[i].f.s;
		int mini=0;
		int bt=0;
		int vt=m-a;
		for(int j=0; j<vec.size(); j++){
			if(i==j){
				continue;
			}
			int ind2=vec[j].s;
			int cn2=vec[j].f.f;
			int las2=-vec[j].f.s;
			if(cn2>cn || (cn2==cn && las2<las)){
				bt++;
				continue;
			}
			if(cn2<=cn){
				int tak=cn-cn2+1;
				if(tak<=vt){
					vt-=tak;
					bt++;
				}
				continue;
			}
		
		}
		
		if(bt<k && cn!=0){
			ans[ind]=1;
			
			continue;
		}
		bt=0;
		for(int j=0; j<vec.size(); j++){
			if(i==j){
				continue;
			}
			int cn2=vec[j].f.f;
			int las2=-vec[j].f.s;
			if(cn>cn2 || (cn==cn2 && las<las2)){
				bt++;
				continue;
			}
			if(cn+m-a>cn2){
				bt++;
				continue;
			}
		}
		
		if(bt>=n-k){
			ans[ind]=2;
		}
		else{
			ans[ind]=3;
		}
		if(m==a && cn==0){
			ans[ind]=3;
		}
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}