#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n,m;
	cin>>n>>m;
	int ans=1;
	for(int i=0;i<=30;i++){
		int l=1<<i,r=min(n,(1<<i+1)-1);
		ans=1ll*ans*(max(0,r-l+1)+1)%m;
	}
	cout<<(ans-1+m)%m<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}