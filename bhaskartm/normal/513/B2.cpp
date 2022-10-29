#include <bits/stdc++.h>
using namespace std;
#define int long long int
 main() {
	int n, m;
	cin>>n>>m;
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i]=0;
	}
	int l=0;
	int r=n-1;
	int cnt=0;
	int mini=1;
	int pointer=n-1;
	while(cnt<n){
		cnt++;
		if(m>(1LL<<(pointer-1))){
			arr[r]=mini;
			r--;
			m=m-(1LL<<(pointer-1));
			pointer--;
			mini++;
		}
		else{
			arr[l]=mini;
			mini++;
			l++;
			pointer--;
		}
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}