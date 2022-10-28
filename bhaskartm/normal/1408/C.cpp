#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, l;
		cin>>n>>l;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		T lo=0;
		T hi=1e9;
		T ans=-1;
		for(int i=0; i<80; i++){
			T mid=(lo+hi)/2;
			T x=0;
			T rem=mid;
			int sp=1;
			for(int j=0; j<n; j++){
				int gap;
				if(j==0){
					gap=arr[j];
				}
				else{
					gap=arr[j]-arr[j-1];
				}
				T tim=(gap*1.0)/sp;
				if(rem>tim){
					x=arr[j];
					rem-=tim;
					sp++;
					continue;
				}
				else{
					x+=(rem)*sp;
					rem=0;
					
					break;
				}
			}
			if(rem>0){
				x+=(sp)*rem;
			}
			T x2=l;
			rem=mid;
			sp=1;
			for(int j=n-1; j>=0; j--){
				int gap;
				if(j==n-1){
					gap=l-arr[n-1];
				}
				else{
					gap=arr[j+1]-arr[j];
				}
				T tim=(gap*1.0)/sp;
				if(rem>tim){
					rem-=tim;
					sp++;
					x2=arr[j];
					continue;
				}
				else{
					x2-=sp*rem;
					rem=0;
					break;
				}
			}
			if(rem>0){
				x2-=rem*sp;
			}
			if(x2<x){
				ans=mid;
				hi=mid;
			}
			else{
				lo=mid;
			}
		}
		cout<<setprecision(20)<<ans<<endl;
	}
	return 0;
}