#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n];
	int loc=-1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==n)loc=i;
	}
	int last=n;
	for(int i=loc+1;i<n;i++){
		if(arr[i]<last){
			last=arr[i];
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	last=n;
	for(int i=loc-1;i>=0;i--){
		if(arr[i]<last){
			last=arr[i];
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
    return 0;
}