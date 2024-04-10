#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int t,n,a[200004];
set<int>p;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		if(n==2){
			cout<<a[1]<<" "<<a[2]<<"\n";
			continue;
		}
		int mx=2e9,S,T;
		for(int i=2;i<=n;i++)if(a[i]-a[i-1]<mx)mx=a[i]-a[i-1],S=i-1,T=i;
		for(int i=T;i<=n;i++)cout<<a[i]<<" ";
		for(int i=1;i<=S;i++)cout<<a[i]<<" ";
		puts("");
	}
}