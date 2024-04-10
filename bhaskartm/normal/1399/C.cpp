#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second
#define int long long int

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a, a+n);
		int maxi=0;
		for(int i=2; i<=2*n; i++){
			int l=0;
			int r=n-1;
			int num=0;
			while(l<r){
				if(a[l]+a[r]==i){
					num++;
					l++;
					r--;
					continue;
				}
				if(a[l]+a[r]<i){
					l++;
					continue;
				}
				if(a[l]+a[r]>i){
					r--;
					continue;
				}
			}
			maxi=max(maxi, num);
		}
		cout<<maxi<<endl;
	}
	return 0;
}