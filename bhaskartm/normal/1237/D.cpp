#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin>>n;
	int arr[n];
	int maxi=0;
	int mini=1000000001;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		mini=min(mini, arr[i]);
		maxi=max(maxi, arr[i]);
	}
	if(mini*2>=maxi){
		for(int i=0; i<n; i++){
			cout<<-1<<" ";
		}
		return 0;
	}
	int pointer=1;
	multiset<int>s;
	s.insert(arr[0]);
	int ans[n];
	int cnt=1;
	for(int i=0; i<n; i++){
		
		while(1){
			int x;
			if(s.size()>0){
			auto it=s.end();
			it--;
			 x=(*it);
			}
			else{
				x=0;
			}
			if(arr[pointer]*2>=x){
				
				s.insert(arr[pointer]);
				cnt++;
				pointer=(pointer+1)%n;
			}
			else{
				
					ans[i]=cnt-i;
					
					break;
			
				
			}
		}
		s.erase(s.find(arr[i]));
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}