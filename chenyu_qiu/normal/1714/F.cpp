#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int T,n,d12,d23,d31,x,y,z,l,r,m;
int ans[N][2];
void solve()
{
	cin>>n>>d12>>d23>>d31;
	for(int i=1;i<=n;i++)
		ans[i][0]=ans[i][1]=0;
	if(d12>=d23&&d12>=d31)
	{
		l=1; r=2; m=3;
		if(d23<=d31) x=d23,y=d31,z=d12;
		else swap(l,r),x=d31,y=d23,z=d12;
	}
	else if(d23>=d12&&d23>=d31)
	{
		l=2; r=3; m=1;
		if(d12<=d31) swap(l,r),x=d12,y=d31,z=d23;
		else x=d31,y=d12,z=d23;
	}
	else if(d31>=d12&&d31>=d23)
	{
		l=1; r=3; m=2;
		if(d12<=d23) swap(l,r),x=d12,y=d23,z=d31;
		else x=d23,y=d12,z=d31;
	}
	if((z+x-y)&1) {cout<<"NO\n"; return;}
	int t=(z+x-y)/2;
	if(t<1||t>x||z+x-t>=n) {cout<<"NO\n"; return;}
	ans[1][0]=l;
	ans[z][1]=r;
	if(t==x) ans[y][1]=ans[y+1][0]=m;
	else ans[z+x-t][1]=m,ans[z+1][0]=3+z-t;
	for(int i=1,j=4;i<=z+x-t;i++)
		if(!ans[i][1])
			ans[i][1]=ans[i+1][0]=j,j++;
	for(int i=z+x-t+1;i<n;i++)
		ans[i][0]=1,ans[i][1]=i+1;
	cout<<"YES\n";
	for(int i=1;i<n;i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}