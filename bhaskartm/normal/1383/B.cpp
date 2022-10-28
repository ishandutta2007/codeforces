#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define pb push_back
#define f first
#define s second
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int ans=0;
		
		for(int i=30; i>=0; i--){
			int cnt=0;
			for(int j=0; j<n; j++){
				if((arr[j]&(1<<i))!=0){
					cnt++;
				}
			}
			if(cnt==0){
				continue;
			}
			if(cnt%2==0){
				for(int j=0; j<n; j++){
					if((arr[j]&(1<<i))!=0){
						arr[j]-=(1<<i);
					}
				}
				continue;
			}
			if(cnt==1){
				ans=2;
				break;
			}
			if(cnt%4==1){
				ans=2;
				break;
			}
			if(cnt%4==3){
				if(n%2==1){
					ans=1;
					break;
				}
				else{
					ans=2;
					break;
				}
			}
		}
		if(ans==2){
			cout<<"WIN"<<endl;
			continue;
		}
		if(ans==1){
			cout<<"LOSE"<<endl;
			continue;
		}
		if(ans==0){
			cout<<"DRAW"<<endl;
			continue;
		}
	}
	return 0;
}