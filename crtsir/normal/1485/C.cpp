#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int x,y,i,tmp;
		scanf("%d%d",&x,&y);
		long long ans=0;
		for(i=1;i<=y&&x>=i*i-1;i++)
			ans+=(i-1);
		tmp=i;
		for(i=1;i<=32000;i++)
			ans+=max(min(y,(x-i)/i)-tmp+1,0);
		cout<<ans<<endl;
	}
}