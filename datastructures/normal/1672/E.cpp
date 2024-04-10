#include <iostream>
#include <cstdio>
using namespace std;
int n,ans,sum;
int ask(int w){
	cout<<"? "<<w<<endl;
	int x;
	cin>>x;
	return x;
}
int main(){
	cin>>n;
	int l=1,r=1e8;
	while(l<=r){
		int mid=(l+r)/2;
		if (ask(mid)==1)ans=mid,r=mid-1;
		else l=mid+1;
	}
	sum=ans-n+1;
	for (int i=1;i<=n;i++){
		int w=(sum+n-1)/i;
		int h=ask(w);
		if (h!=0)ans=min(ans,w*h);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}