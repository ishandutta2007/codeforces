#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,a[555];
int main(){
	int t; cin>>t; while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int x;
		for(int i=1;i<=n;++i)if(a[i]!=i){x=i;break;}
		for(int i=1;i<=n;++i)if(a[i]==x){reverse(a+x,a+i+1);break;}
		for(int i=1;i<=n;++i)printf("%d ",a[i]); puts("");
	}
	
}