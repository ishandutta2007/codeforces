#include <bits/stdc++.h>
using namespace std;
int cnt[200005];

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		cnt[arr[i]]++;
	}
	int i=200000;
	int j=200000;
	
	int index=-1;
	int maxi=0;
	while(i>0 && j>0){
		while( i>0 && cnt[i]==0){
			i--;
		}
		int ans=0;
		ans=cnt[i];
		
		j=i-1;
		while(cnt[j]>1){
			ans=ans+cnt[j];
			j--;
		}
		if(cnt[j]==1){
			ans++;
		}
		
		if(ans>maxi){
			index=i;
			maxi=ans;
		}
		i=j;
	}
	cout<<maxi<<endl;
	int last=0;
	for(int i=index; i>=0; i--){
		
		if(i==index){
			for(int j=0; j<cnt[i]; j++){
				cout<<i<<" ";
			}
			continue;
		}
		if(cnt[i]>1){
			for(int j=0; j<cnt[i]-1; j++){
				cout<<i<<" ";
			}
			continue;
		}
		if(cnt[i]==1){
			cout<<i<<" ";
			last=i+1;
			break;
		}
		if(cnt[i]==0){
			last=i+1;
			break;
		}
	}
	
	for(int i=last; i<index; i++){
		cout<<i<<" ";
	}
	
	return 0;
}