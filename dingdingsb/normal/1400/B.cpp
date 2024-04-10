#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int p,f,cnts,cntw,s,w,ans=0;
		cin>>p>>f>>cnts>>cntw>>s>>w;
		if(s>w){
			swap(s,w);
			swap(cnts,cntw);
		}
		for(int x1=0;x1<=min(cnts,p/s);x1++){
			int y1=min(cntw,(p-x1*s)/w);
			int x2=min(cnts-x1,f/s);
			int y2=min(cntw-y1,(f-x2*s)/w);
			ans=max(ans,x1+x2+y1+y2);
		}
		cout<<ans<<endl;
	}
	return 0;
}