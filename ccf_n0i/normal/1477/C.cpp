#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,j,px[5005],py[5005],v[5005],lst;
long long dis(int x,int y){
	return 1ll*(px[x]-px[y])*(px[x]-px[y])+1ll*(py[x]-py[y])*(py[x]-py[y]);
}
int main(){
	cin>>n;
	rep(i,n)cin>>px[i]>>py[i];
	v[lst=1]=1;
	cout<<1;
	rep(i,n-1){
		int t=0;
		rep(j,n)if(!v[j]){
			if(!t||dis(lst,j)>dis(lst,t)) t=j; 
		}
		v[lst=t]=1;
		cout<<' '<<t; 
	}
	return 0;
}