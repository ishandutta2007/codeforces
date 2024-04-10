#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[n+1];
	arr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	int q,l,r;
	cin>>q;
	while(q--){
		cin>>l>>r;
		printf("%d\n",(arr[r]-arr[l-1])/10);
	}
	return 0;
}