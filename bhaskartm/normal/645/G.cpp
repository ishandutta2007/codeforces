#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
#define pi 3.14159265358979323846
#define EPS 1e-3
const int N=1e5+5;
int n, a;
int x[N];
int y[N];
int iter=0;


bool fu(T r){
	vector<pair<T, T>>vec;
	iter++;
	for(int i=0; i<n; i++){
		T rr=sqrt((x[i]+a)*(x[i]+a)+y[i]*y[i]);
		T dis=sqrt((x[i]-a)*(x[i]-a)+y[i]*y[i]);
		if(dis>rr+r || dis<fabs(rr-r)){
			continue;
		}
		T ang=atan2(y[i], x[i]-a);
		T ang2=acos((r*r+dis*dis-rr*rr)/(2*r*dis));
		T le=ang-ang2;
		T ri=ang+ang2;
		while(le<0){
			le+=2*pi;
		}
		while(le>=2*pi){
			le-=2*pi;
		}
		while(ri<0){
			ri+=2*pi;
		}
		while(ri>=2*pi){
			ri-=2*pi;
		}
		if(le>ri){
			swap(le, ri);
		}
		
		
		
		vec.pb({le, ri});
		
		//vec.pb({le+2*pi, ri+2*pi});
	}
	sort(vec.begin(), vec.end());
	
	
	set<T>se;
	for(auto u:vec){
		auto it=se.lower_bound(u.f);
		if(it!=se.end() && (*it)<u.s){
			
			return 1;
		}
		se.insert(u.s);
	}
	return 0;
	
}
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>a;
	
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	
	T lo=0;
	T hi=2*a;
	T ans=2*a;
	for(int i=0; i<50; i++){
		T mid=(lo+hi)/2;
		if(fu(mid)){
			ans=mid;
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;
	
	
	return 0;
}