#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	lli arr[n];
	lli arr2[m];
	lli sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<m;i++){
		cin>>arr2[i];
		sum+=arr2[i];
	}
	sort(arr,arr+n);
	sort(arr2,arr2+m);
	for(int i=n-1;i>=0;i--){
		if(arr[i]>arr2[0]) {
			printf("-1\n");
			return 0;
		}
	}
	if(m==1){
		sum=0;
		bool work=false;
		for(int i=0;i<n;i++){
			if(arr[i]==arr2[0]){
				work=true;
			}
			sum+=arr[i];
		}
		if(!work){
			printf("-1\n");
			return 0;
		}
		printf("%lli\n",sum);
		return 0;
	}
	if(n==1){
		sum=0;
		bool work=false;
		for(int i=0;i<m;i++){
			if(arr2[i]==arr[0]){
				work=true;
			}
			sum+=arr2[i];
		}
		if(!work){
			printf("-1\n");
			return 0;
		}
		printf("%lli\n",sum);
		return 0;
	}
	bool can=false;
	for(int i=0;i<m;i++){
		if(arr2[i]==arr[n-1]){
			can=true;
		}
	}
	if(can){
		sum+=arr[n - 2] * (m);
	}
	else {
		sum+=arr[n-1];
		sum += arr[n - 2] * (m - 1);
	}
	for(int i=0;i<n-2;i++){
		sum+=arr[i]*m;
	}
	printf("%lli\n",sum);
}