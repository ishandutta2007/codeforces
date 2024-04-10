#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>arr;
int n, m;
 
bool f(int cn){
	if(cn>2){
		return 0;
	}
	for(int i=1; i<n; i++){
		int val=0;
		for(int j=0; j<m; j++){
			if(arr[i][j]!=arr[0][j]){
				val++;
			}
		}
		if(val>4){
			return 0;
		}
		if(val<=2){
			continue;
		}
		for(int j=0; j<m; j++){
			if(arr[i][j]!=arr[0][j]){
				int temp=arr[0][j];
				arr[0][j]=arr[i][j];
				if(f(cn+1)){
					return 1;
				}
				arr[0][j]=temp;
			}
		}
		return 0;
	}
	return 1;
}
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	arr.resize(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int x;
			cin>>x;
			arr[i].pb(x);
		}
	}
	if(!f(0)){
		cout<<"No";
		return 0;
	}
	else{
		cout<<"Yes"<<endl;
		for(int i=0; i<m; i++){
			cout<<arr[0][i]<<" ";
		}
		return 0;
	}
	return 0;
}