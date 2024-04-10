#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
const T pi=acos(-1);
const T EPS=1e-10;
const int N=2005;
int n, m;
pair<T, int>q[4*N+5];
 
struct PT{
	int x, y, c;
}a[N];
 
 
bool f(int ind, T r){
	int tot=0;
	if(a[ind].c==1){
		
		q[++tot]={0, -1};
		q[++tot]={2*pi, 1};
	}
	for(int i=1; i<=n+m; i++){
		if(i==ind){
			continue;
		}
		T ang=atan2(a[ind].y-a[i].y, a[ind].x-a[i].x);
		T dis=(a[ind].y-a[i].y)*(a[ind].y-a[i].y)+(a[ind].x-a[i].x)*(a[ind].x-a[i].x);
		if(dis+EPS>4*r*r){
			continue;
		}
		T ang2=acos(sqrt(dis)/(2*r));
		T le=ang-ang2;
		T ri=ang+ang2;
		if(le<0){
			le+=2*pi;
		}
		if(le>2*pi){
			le-=2*pi;
		}
		if(ri<0){
			ri+=2*pi;
		}
		if(ri>2*pi){
			ri-=2*pi;
		}
		q[++tot]={le, -a[i].c};
		q[++tot]={ri, a[i].c};
		if(le>ri+EPS){
			q[++tot]={0, -a[i].c};
			q[++tot]={2*pi, a[i].c};
		}
	}
	sort(q+1, q+tot+1);
 
	
	int sum[3];
	sum[1]=0;
	sum[2]=0;
	for(int i=1; i<=tot; i++){
		sum[abs(q[i].s)]+=(q[i].s<0?1:-1);
		if(sum[1] && !sum[2]){
			return 1;
		}
		
	}
	return 0;
}
 
 
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	for(int i=1; i<=n+m; i++){
		cin>>a[i].x;
		cin>>a[i].y;
		a[i].c=(i<=n?1:2);
	}
	
	T maxi=3e8;
	T ans=0;
	
	for(int i=1; i<=n+m; i++){
		if(f(i, maxi)){
			cout<<-1;
			return 0;
		}
	}
	
	for(int i=1; i<=n+m; i++){
		if(!f(i, ans)){
			continue;
		}
		
		T l=ans;
		T r=maxi;
		for(int g=0; g<45; g++){
			T mid=(l+r)/2;
			if(f(i, mid)){
				
				l=mid;
				ans=mid;
			}
			else{
				
				r=mid;
			}
		}
	}
	cout<<setprecision(20)<<ans;
	return 0;
}