#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define PI                3.14159265358979323846
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int pw(int a,int b,int p){
	if(b==0)return 1;
	int t=pw(a,b/2,p);
	if(b%2)return (((a*t)%p)*t)%p;
	else return ((t*t)%p);
}

void solve(){
	cout<<setprecision(9);
	cout<<fixed;
	int n;vc<double> vv;double v=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		double r=atan2(y,x);
		vv.pb(r);
	}
	sort(all(vv));
	for(int i=0;i<n-1;i++){
		v=max(v,vv[i+1]-vv[i]);
	}
	v=max(v,2*PI-(vv[n-1]-vv[0]));
	cout<<180*(2*PI-v)/PI;
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}