#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=4e5+5;
int arr[N];
int n; 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>arr[i];
		}
		int tot=0;
		for(int i=1; i<=n; i++){
			if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
				int val=max(arr[i-1], arr[i+1]);
				tot+=(arr[i]-val);
				arr[i]=val;
			}
		}
		for(int i=0; i<=n; i++){
			tot+=abs(arr[i+1]-arr[i]);
		}
		cout<<tot<<endl;
		for(int i=1; i<=n; i++){
			arr[i]=0;
		}
	}
	return 0;
}