#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;

int main(){
	ll t,n,k,d,ans,x;
	cin >> t;
	loop(t){
		cin >> n >> k >> d;
		ll a[n],b[k+1];
		for(int j=0; j<n; j++) cin >> a[j];
		for(int j=0; j<=k; j++) b[j]=0;
		for(int j=0; j<d; j++) b[a[j]]++;
		ans=0;
		for(int j=0; j<=k; j++){
			if(b[j]>0) ans++;
		}
		for(int j=0; j<n-d; j++){
			if(j==0) x=ans;
			if(a[j+d]==a[j]) continue;
			b[a[j+d]]++;
			b[a[j]]--;
			if(b[a[j+d]]==1) x++;
			if(b[a[j]]==0) x--;
			ans=min(x,ans);
		}
		cout << ans << endl;
	}
	return 0;
}