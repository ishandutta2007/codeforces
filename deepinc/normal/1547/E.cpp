#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int T[333333],a[333333],c[333333];
int main(){
	int t;cin>>t;while(t--){
		int n,k; cin>>n>>k;
		for(int i=1;i<=n;++i)T[i]=1.1e9;
		for(int i=1;i<=k;++i)scanf("%d",&a[i]);
		for(int i=1;i<=k;++i)scanf("%d",&T[a[i]]);
		for(int i=2;i<=n;++i)T[i]=min(T[i],T[i-1]+1);
		for(int i=n-1;i;--i)T[i]=min(T[i],T[i+1]+1);
		for(int i=1;i<=n;++i)printf("%d ",T[i]); puts("");
	}
}