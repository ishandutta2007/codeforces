
#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T double
#define EPS 1e-10
#define pi acos(-1)
const int N=1005;
int xx[N];
int yy[N];
T x[N];
T y[N];
T dis[N][N];
 
T w, h;
int n;
struct eve{double x;int ad;}e[10000+5];
int top;
int tot;
 
 
 
void add(T l, T r, int val){
	while(l>2*pi){
		l-=2*pi;
	}
	while(l<0){
		l+=2*pi;
	}
	while(r>2*pi){
		r-=2*pi;
	}
	while(r<0){
		r+=2*pi;
	}
	e[++top]=(eve){l, -val};
	e[++top]=(eve){r+EPS, val};
	if(l>r+EPS){
		tot+=val;
	}
}
 
bool cmp(const eve& a, const eve& b){
	return a.x<b.x;
}
 
bool f(int ind, T r){
	top=0;
	tot=0;
	for(int i=0; i<n; i++){
		if(i==ind){
			continue;
		}
		T d=dis[i][ind];
		if(d+EPS>2*r){
			continue;
		}
		if(d<EPS){
			continue;
		}
		T ang=atan2(y[i]-y[ind], x[i]-x[ind]);
		T ang2=acos(d/(2*r));
		add(ang-ang2, ang+ang2, 1);
		
	}
	if(x[ind]<r){
		add(pi-acos(x[ind]/r), pi+acos(x[ind]/r), 2);
	}
	if(x[ind]>w-r){
		add(-acos((w-x[ind])/r), acos((w-x[ind])/r), 2);
	}
	if(y[ind]<r){
		add((3*pi/2)-acos(y[ind]/r), (3*pi/2)+acos(y[ind]/r), 2);
 
	}
	if(y[ind]>h-r){
		add((pi/2)-acos((h-y[ind])/r), (pi/2)+acos((h-y[ind])/r), 2);
	}
	sort(e+1, e+top+1, cmp);
	if(tot<2){
		return 1;
	}
	for(int i=1; i<=top; i++){
		tot-=e[i].ad;
		if(tot<2){
			return 1;
		}
	}
	return 0;
}
 
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mt19937_64 rnd(time(NULL));
	cin>>w>>h>>n;
	for(int i=0; i<n; i++){
		cin>>xx[i]>>yy[i];
		x[i]=xx[i];
		y[i]=yy[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			dis[i][j]=dis[j][i]=sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
		}
	}
	T ans=0;
	T maxi=sqrt(w*w+h*h);
	vector<int>vec;
	for(int i=0; i<n; i++){
		vec.pb(i);
	}
	for(int i=0; i<10; i++){
		random_shuffle(vec.begin(), vec.end());
	}
	for(auto i:vec){
		if(!f(i, ans+5*EPS)){
			continue;
		}
		T lo=ans;
		T hi=maxi;
		for(int rep=0; rep<50; rep++){
			T mid=(lo+hi)/2;
			if(f(i, mid)){
				ans=mid;
				lo=mid;
			}
			else{
				hi=mid;
			}
		}
		
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;
	return 0;
}