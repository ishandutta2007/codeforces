#include<bits/stdc++.h>
#define int long long
const int N=100050;
using namespace std;

int a[N],b[N],n,q,ans,x,y,z;

void chg(int x,int p=1){if(x-1&&x<=n)ans+=max(b[x],0ll)*p;}

main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i]-a[i-1],chg(i);
	cout<<(ans+b[1]+1>>1)<<endl;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x>>y>>z;
		chg(x,-1),chg(y+1,-1);
		b[x]+=z,b[y+1]-=z;
		chg(x),chg(y+1);
		cout<<(ans+b[1]+1>>1)<<endl;
	}
}