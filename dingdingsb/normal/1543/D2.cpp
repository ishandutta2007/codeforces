// Problem: D2. RPD and Rap Sheet (Hard Version)
// Contest: Codeforces - Codeforces Round #730 (Div. 2)
// URL: https://codeforces.ml/contest/1543/problem/D2#
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int t,n,k;
int ask(int x){
	cout<<x<<endl;cout.flush();
	cin>>x;return x;
}
int odec(int x,int y){
	int z=0;int t=1;
	while(x||y){
		int X=x%k,Y=y%k;
		int Z=X-Y;if(Z<0)Z+=k;
		z+=Z*t;
		x/=k,y/=k;t*=k;
	}return z;
}
int oplus(int x,int y){
	int z=0;int t=1;
	while(x||y){
		int X=x%k,Y=y%k;
		int Z=Y+X;if(Z>=k)Z-=k;
		z+=Z*t;
		x/=k,y/=k;t*=k;
	}return z;
}
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int a=0;
		for(int x=0;x<n;x++){
			if(x%2==1){
				if(ask(odec(a,x)))break;
				a=odec(odec(a,x),a);
			}else{
				if(ask(oplus(x,a)))break;
				a=odec(oplus(x,a),a);
			}
		}
	}return 0;
}