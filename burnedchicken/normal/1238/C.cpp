#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(long long int i=0; i<a; i++)
 
using namespace std;

int main(){
	ll q,h,n,x,ans;
	cin >> q;
	loop(q){
		cin >> h >> n;
		ll a[n];
		for(int j=n-1; j>=0; j--) cin >> a[j];
		x=ans=0;
		if(n==1){
			cout << 0 << endl;
			continue;
		}
		if(n==2){
			if(a[0]==1){
				cout << 0 << endl;
				continue;
			}
			else{
				cout << 1 << endl;
				continue;
			}
		}
		for(int j=0; j<n-1; j++){
			if(a[j]-j==1) continue;
			x++;
			if(a[j+1]>a[j]+1||j==n-2){
				if(x%2==1) ans++;
				x=0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}