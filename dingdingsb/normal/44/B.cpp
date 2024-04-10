#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,ans=0;
signed main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=0;i<=b;i++)
		for(int j=0;j<=c;j++){
			int rest=n-i-j*2;
			if(rest>=0&&rest*2<=a)
				ans++;
		}
	cout<<ans;
}