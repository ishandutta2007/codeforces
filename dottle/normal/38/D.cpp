#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n;
int a[N],b[N],c[N],d[N];
int w;
double x,y;

bool check(int k){
	x=(a[k]+c[k])/2.,y=(b[k]+d[k])/2.;
	w=(c[k]-a[k])*(d[k]-b[k])*(c[k]-a[k]);
	for(int i=k-1;i>=1;i--){
		double nx=(a[i]+c[i])/2.,ny=(b[i]+d[i])/2.,
			nw=(c[i]-a[i])*(d[i]-b[i])*(c[i]-a[i]);
		if(x<a[i]||x>c[i])return 0;
		if(y<b[i]||y>d[i])return 0;
		double l=nw/(nw+w);
		x+=(nx-x)*l,y+=(ny-y)*l;
		w+=nw;
	}
	return 1;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
		if(a[i]>c[i])swap(a[i],c[i]);
		if(b[i]>d[i])swap(b[i],d[i]);
	}
	for(int i=1;i<=n;i++)
		if(!check(i))
			cout<<i-1<<endl,exit(0);
	cout<<n<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}