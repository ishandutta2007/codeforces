#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define int long long int 
main() {
	int r, c;
	cin>>r>>c;
	if(r==1 && c==1){
		cout<<0;
		return 0;
	}
	if(r==1){
		for(int i=2; i<=c+1; i++){
			cout<<i<<" ";
		}
		return 0;
	}
	if(c==1){
		for(int i=2; i<=r+1; i++){
			cout<<i<<endl;
		}
		return 0;
	}
	int arr[r][c];
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			arr[i][j]=(i+1)*(r+j+1);
		}
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}