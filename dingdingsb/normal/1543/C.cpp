// Problem: C. Need for Pink Slips
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.ml/contest/1543/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
double a[3],v;
const double eps=1e-6;
double dfs(){
	double b[3];memcpy(b,a,sizeof a);
	if(a[0]<=eps&&a[1]<=eps)return 1;
	if(a[0]<=eps){
		a[1]-=v;
		return 1+b[1]*dfs();
	}
	if(a[1]<=eps){
		a[0]-=v;
		return 1+b[0]*dfs();
	}
	double ans=1;
	if(a[0]<=v){
		a[1]+=a[0]/2;
		a[2]+=a[0]/2;
		a[0]=0;
		ans+=b[0]*dfs();
	}else{
		a[1]+=v/2;
		a[2]+=v/2;
		a[0]-=v;
		ans+=b[0]*dfs();
	}
	memcpy(a,b,sizeof a);
	if(a[1]<=v){
		a[0]+=a[1]/2;
		a[2]+=a[1]/2;
		a[1]=0;
		ans+=b[1]*dfs();
	}else{
		a[0]+=v/2;
		a[2]+=v/2;
		a[1]-=v;
		ans+=b[1]*dfs();
	}
	return ans;
}
signed main(){
	int t;cin>>t;
	while(t--){
		cin>>a[0]>>a[1]>>a[2]>>v;
		printf("%.12lf\n",dfs());
	}
}