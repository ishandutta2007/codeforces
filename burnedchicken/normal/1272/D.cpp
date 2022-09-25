#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	loop(n) cin >> a[i];
	int arr1[n],arr2[n];
	loop(n){
		if(i==0) arr1[i]=1;
		else if(a[i]>a[i-1]) arr1[i]=arr1[i-1]+1;
		else arr1[i]=1;
		if(i==0) arr2[n-1-i]=1;
		else if(a[n-1-i]<a[n-i]) arr2[n-1-i]=arr2[n-i]+1;
		else arr2[n-1-i]=1;
	}
	int ans=1;
	loop(n) ans=max(ans,arr1[i]);
	loop(n){
		if(i==0||i==n-1) continue;
		if(a[i+1]>a[i-1]) ans=max(ans,arr1[i-1]+arr2[i+1]);
	}
	cout << ans << "\n";
	return 0;
}