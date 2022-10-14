#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	lli arr[n];
	lli mink=1000000000;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mink=min(mink,arr[i]/max((i==0?1:(i-0)),(i==n-1?1:(n-1-i))));
	}
	printf("%d\n",mink);
}