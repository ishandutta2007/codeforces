#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const int N=1e5+5;
int arr[N];
int li[N];
int mli[N];
int ld[N];
int mld[N];
int ri[N];
int mri[N];
int rd[N];
int mrd[N];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	li[1]=1;
	ld[1]=1;
	int ans=0;
	for(int i=2; i<=n; i++){
		if(arr[i]>arr[i-1]){
			li[i]=li[i-1]+1;
			ld[i]=1;
		}
		else{
			ld[i]=ld[i-1]+1;
			li[i]=1;
		}
		mli[i]=max(mli[i-1], li[i]);
		mld[i]=max(mld[i-1], ld[i]);
	}
	ri[n]=1;
	rd[n]=1;
	for(int i=n-1; i>=1; i--){
		if(arr[i+1]>arr[i]){
			ri[i]=ri[i+1]+1;
			rd[i]=1;
		}
		else{
			ri[i]=1;
			rd[i]=rd[i+1]+1;
		}
		mri[i]=max(mri[i+1], ri[i]);
		mrd[i]=max(mrd[i+1], rd[i]);
	}
	for(int i=2; i<n; i++){
		int d1=li[i];
		int d2=rd[i];
		int d3=max(d1, d2);
		if(d1==1 || d2==1){
			continue;
		}
		if(d1!=d2){
			continue;
		}
		if(d1%2==0){
			continue;
		}
		int val=0;
		val=max(val, mli[i-d1]);
		val=max(val, mld[i-d1+1]);
		val=max(val, mri[i+d2-1]);
		val=max(val, mrd[i+d2]);
		if(val<d3){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}