#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;cin>>t;while(t--){
		int n;ll tot=0;
		scanf("%d",&n);
		for(int i=1,x;i<=n;++i)scanf("%d",&x),tot+=x;
		tot%=n;
		if(tot)printf("%lld\n",tot*(n-tot));
		else puts("0");
	}
}