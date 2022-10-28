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
	T x, y, x2, y2;
	cin>>x>>y>>x2>>y2;
	T v, t;
	cin>>v>>t;
	T vx, vy, wx, wy;
	cin>>vx>>vy>>wx>>wy;
	T x3=x2-t*vx;
	T y3=y2-t*vy;
	T dis=sqrt((x-x3)*(x-x3)+(y-y3)*(y-y3));
	
	if((dis/v)>t){
		T lo=t;
		T hi=1e18;
		for(int i=0; i<100; i++){
			T mid=(lo+hi)/2;
			T xx=x3-(mid-t)*wx;
			T yy=y3-(mid-t)*wy;
			
			T dis=sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
			if((dis/v)>mid){
				lo=mid;
			}
			else{
				hi=mid;
			}
		}
		cout<<setprecision(20)<<lo<<endl;
	}
	else{
		T lo=0;
		T hi=1e18;
		
		for(int i=0; i<100; i++){
			T mid=(lo+hi)/2;
			T xx=x2-mid*vx;
			T yy=y2-mid*vy;
			T dis=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
			if((dis/v)>mid){
				lo=mid;
			}
			else{
				hi=mid;
			}
		}
		cout<<setprecision(20)<<lo<<endl;
	}
	return 0;
}