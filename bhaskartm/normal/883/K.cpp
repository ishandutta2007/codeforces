#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int

#define f first
#define s second
#define pb push_back
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	int a[n];
	int b[n];
	int tot=0;
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
		tot+=a[i];
	}
	int c[n];
	int d[n];
	c[0]=a[0];
	d[0]=a[0]+b[0];
	
	for(int i=1; i<n; i++){
		c[i]=max(a[i], c[i-1]-1);
		d[i]=min(a[i]+b[i], d[i-1]+1);
		if(c[i]>d[i]){
			cout<<-1;
			return 0;
		}
	}
	
	int ans[n];
	ans[n-1]=d[n-1];
	for(int i=n-2; i>=0; i--){
		if(ans[i+1]+1>=c[i] && ans[i+1]+1<=d[i]){
			ans[i]=ans[i+1]+1;
		}
		else if(ans[i+1]>=c[i] && ans[i+1]<=d[i]){
			ans[i]=ans[i+1];
		}
		else{
			ans[i]=ans[i+1]-1;
		}
	}
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=ans[i];
	}
	
	cout<<sum-tot<<endl;
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}