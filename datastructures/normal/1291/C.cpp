#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,n,m,k,a[10005],ans;
inline int work(int l,int r,int rest){
//	cout<<l<<' '<<r<<' '<<rest<<endl;
	int s=2e9;
	for (int i=0;i<=rest;i++){
//		cout<<l+i<<' '<<r-(rest-i)<<endl;
		s=min(s,max(a[l+i],a[r-(rest-i)]));
	}
	return s;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		if (k>m-1)k=m-1;
		ans=0;
		for (int i=0;i<=k;i++){
			ans=max(ans,work(1+i,n-(k-i),m-1-k)); 
		}
		cout<<ans<<endl;
	}
	return 0;
}