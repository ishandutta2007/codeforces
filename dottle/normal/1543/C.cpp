#include<bits/stdc++.h>
//#define int long long
//const int N=
const double eps=1e-12;
using namespace std;

double ans;

void dfs(int k,double p,double a,double b,double c,double v){
	ans+=p*c*(k+1);
	if(a<eps&&b<eps)return;
	double A,B,C;
	if(a>eps){
		double d=min(a,v);
		A=a-d,B=b,C=c;
		if(b<eps)C+=d;
		else B+=d/2,C+=d/2;
		dfs(k+1,p*a,A,B,C,v);
	}
	if(b>eps){
		double d=min(b,v);
		A=a,B=b-d,C=c;
		if(a<eps)C+=d;
		else A+=d/2,C+=d/2;
		dfs(k+1,p*b,A,B,C,v);
	}
}

void solve(){
	double a,b,c,v;
	ans=0;
	cin>>a>>b>>c>>v;
	dfs(0,1,a,b,c,v);
	cout<<setprecision(12)<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}