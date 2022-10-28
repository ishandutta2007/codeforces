#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int ans1=0;
	int ans2=0;
	vector<int>rem;
	for(int i=0; i<n; i++){
		int c;
		cin>>c;
		int arr[c];
		for(int j=0; j<c; j++){
			cin>>arr[j];
		}
		if(c%2==1){
		for(int j=0; j<((c-1)/2); j++){
			ans1+=arr[j];
		}
		for(int j=c-1; j>((c-1)/2); j--){
			ans2+=arr[j];
		}
		
			rem.push_back(arr[(c-1)/2]);
		
		}
		else{
			for(int j=0; j<(c/2); j++){
				ans1+=arr[j];
			}
			for(int j=(c/2); j<c; j++){
				ans2+=arr[j];
			}
		}
	}
	sort(rem.begin(), rem.end());
	reverse(rem.begin(), rem.end());
	int c=0;
	for(int i=0; i<rem.size(); i++){
		if(c==0){
			ans1+=rem[i];
		}
		else{
			ans2+=rem[i];
		}
		c=1-c;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}