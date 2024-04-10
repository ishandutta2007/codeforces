#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int de[200002];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(arr[n-1]<arr[n-2]+arr[n-3]){
		printf("YES\n");
		de[100000]=arr[n-1];
		int le=100000;
		int ri=100000;
		bool left=false;
		for(int i=n-2;i>=0;i--){
			if(left){
				de[--le]=arr[i];
			}
			else{
				de[++ri]=arr[i];
			}
			left=!left;
		}
		for(int i=le;i<=ri;i++){
			printf("%d ",de[i]);
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}