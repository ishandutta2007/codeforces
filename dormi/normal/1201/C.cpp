#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	lli k;
	cin>>n>>k;
	lli arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	arr[n]=LLONG_MAX;
	sort(arr,arr+n);
	int mid=n/2;
	int right=mid;
	while(k>0){
		if(right+1==n)break;
		lli togo=arr[right+1]-arr[right];
		if(togo*(right-mid+1)<=k) {
			arr[mid] = arr[right + 1];
			k-=togo*(right-mid+1);
			right+=1;
		}
		else{
			arr[mid]+=k/(right-mid+1);
			k=0;
		}
	}
	arr[mid]+=k/(right-mid+1);
	printf("%lli\n",arr[mid]);
	return 0;
}