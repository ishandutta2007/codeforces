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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char arr[n][n];
		int tots=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>arr[i][j];
				if(arr[i][j]=='X'){
					tots++;
				}
			}
		}
		
		for(int cnt=0; cnt<3; cnt++){
			int val=cnt;
			int nums[n][n];
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					nums[i][j]=0;
				}
			}
			for(int i=0; i<n; i++){
				for(int j=val; j<n; j=j+3){
					nums[i][j]=1;
				}
				val=(val+1)%3;
			}
			int tot=0;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(nums[i][j]==1 && arr[i][j]=='X'){
						tot++;
					}
				}
			}
			if(tot<=(tots/3)){
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(arr[i][j]=='.'){
							cout<<arr[i][j];
						}
						else if(nums[i][j]==0){
							cout<<'X';
						}
						else{
							cout<<'O';
						}
					}
					cout<<endl;
				}
				break;
			}
		}
	}
	return 0;
}