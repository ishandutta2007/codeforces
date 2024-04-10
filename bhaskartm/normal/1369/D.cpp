#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1000000007;
int arr[2000005];
main() {
	arr[1]=0;
	arr[2]=0;
	arr[3]=1;
	arr[4]=1;
	arr[5]=3;
	
	for(int i=6; i<=2000000; i++){
		if(i%3!=0){
			arr[i]=(2*arr[i-2]+arr[i-1])%N;
		}
		else{
			arr[i]=(1+4*arr[i-4]+4*arr[i-3]+arr[i-2])%N;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<(arr[x]*4)%N<<endl;
	}
	return 0;
}