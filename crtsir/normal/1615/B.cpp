#include<bits/stdc++.h>
using namespace std;
int T=1,l,r;
int calc(int nw,int t){
	int ans=(t+1)/(1<<nw+1)*(1<<nw)+max(0,(t+1)%(1<<nw+1)-(1<<nw));
	return ans;
}
int main(){
	cin>>T;
	while(T--){
		cin>>l>>r;
		int ans=0;
		for(int i=0;i<20;i++)
			ans=max(calc(i,r)-calc(i,l-1),ans);
		cout<<r-l+1-ans<<endl;
	}
}