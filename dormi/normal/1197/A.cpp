#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	    	cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    printf("%d\n",min(n-2,arr[n-2]-1));
    }
    return 0;
}