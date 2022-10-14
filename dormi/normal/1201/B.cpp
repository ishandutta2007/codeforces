#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	lli arr[n];
	lli am=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		am+=arr[i];
	}
	sort(arr,arr+n);
	if(arr[n-1]<=am-arr[n-1]&&am%2==0){
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}