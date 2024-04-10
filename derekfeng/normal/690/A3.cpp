#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int n,a=0,x,r;cin>>n>>r;
		for(int i=1;i<n;i++)cin>>x,a+=x;
		cout<<(r-a%n+n)%n+1<<"\n";
	}
}