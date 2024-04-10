#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int>v;
vector<pair<int, int>>v2;
 
bool f(int val){
	vector<int>v3;
	int i=0;
	int j=m-val;
	
	while(v3.size()!=n+val){
		
		if(i<n && j<m){
			if(v[i]>=v2[j].first){
				v3.push_back(v2[j].first);
				j++;
				continue;
			}
			else{
				v3.push_back(v[i]);
				i++;
				continue;
			}
		}
		if(i==n){
			v3.push_back(v2[j].first);
			j++;
		}
		else{
			v3.push_back(v[i]);
			i++;
		}
	}
	
	int index=0;
	int cnt=0;
	bool booly=true;
	while(index<n+val){
		if(v3[index]<cnt){
			booly=false;
			break;
		}
		cnt++;
		index+=k;
	}
	return booly;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>k;
	
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	
	
	for(int i=1; i<=m; i++){
		int x;
		cin>>x;
		v2.push_back({x, i});
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());
	int l=0;
	int h=m;
	int ans=-1;
	
	while(l<=h){
		int mid=((l+h)/2);
		
		if(f(mid)){
			
			ans=mid;
			l=mid+1;
		}
		else{
			h=mid-1;
		}
	}
	
	if(ans==-1){
		cout<<-1<<endl;
		return 0;
	}
	else{
		cout<<ans<<endl;
		reverse(v2.begin(), v2.end());
		for(int i=0; i<ans; i++){
			cout<<v2[i].second<<" ";
		}
	}
	return 0;
}