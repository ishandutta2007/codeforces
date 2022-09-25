#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;

int main(){
	ll t,n,m,w,x,y,z;
	cin >> t;
	loop(t){
		cin >> n;
		ll a[n];
		for(int j=0; j<n; j++) cin >> a[j];
		cin >> m;
		ll b[m];
		for(int j=0; j<m; j++) cin >> b[j];
		w=x=y=z=0;
		for(int j=0; j<n; j++){
			if(a[j]%2==0) w++;
			else x++;
		}
		for(int j=0; j<m; j++){
			if(b[j]%2==0) y++;
			else z++;
		}
		cout << w*y+x*z << endl;
	}
	return 0;
}