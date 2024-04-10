#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
int n,m;
int a[N];
inline int f(int x){
	if(x<0) return -x;
	return x;
}
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		ll x,y;cin>>n>>x>>y;
		for(i=1;i<=n;i++) cin>>a[i];
		int mx=0;
		for(i=1;i<n;i++){
			mx=max(mx,f(a[i]-a[i+1]));
		}
		if(mx==0) cout<<min(y+y,x+y)<<endl;
		else if(mx==1) cout<<min(x,y)<<endl;
		else cout<<0<<endl;
	}
	return 0;
}