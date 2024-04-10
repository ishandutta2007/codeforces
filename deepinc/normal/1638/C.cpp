#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[155555];
int main(){
	int t; cin>>t; while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int mx=0,ans=0;
		for(int i=1;i<=n;++i){
			mx=max(mx,a[i]);
			ans+=mx==i;
		}printf("%d\n",ans);
	}
	
}