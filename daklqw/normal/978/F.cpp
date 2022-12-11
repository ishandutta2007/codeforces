#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 200010
int n,sk[MAXN],rk[MAXN],x,y,ans[MAXN],k,a,b;
inline bool cmp(int a,int b){
	return sk[a]<sk[b];
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>sk[i];
		rk[i]=i;
	}
	sort(rk+1,rk+1+n,cmp);
	while(k--){
		cin>>a>>b;
		if(sk[a]>sk[b])--ans[a];
		else if(sk[a]<sk[b])--ans[b];
	}
	int lt=0;
	for(int i=1;i<=n;++i){
		if(sk[rk[i]]>sk[rk[i-1]])lt=i-1;
		ans[rk[i]]+=lt;
	}
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}