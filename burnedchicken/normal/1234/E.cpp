#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0)
 
using namespace std;
 
int main(){
	IOS;
	ll n,m,x,y;
	cin >> n >> m;
	ll a[m],ans[n+1],tel[n];
	loop(m) cin >> a[i];
	loop(n) tel[i]=0;
	ans[0]=0;
	loop(m-1){
		if(a[i]==a[i+1]) continue;
		x=max(a[i],a[i+1]);
		y=min(a[i],a[i+1]);
		tel[0]=tel[0]+x-y;
		tel[y-1]=tel[y-1]+y-1;
		tel[y]=tel[y]-y;
		tel[x-1]=tel[x-1]-x+2*y+1;
		if(x!=n) tel[x]=tel[x]+x-2*y;
	}
	loop(n) ans[i+1]=ans[i]+tel[i];
	loop(n) cout << ans[i+1] << " ";
	cout << endl;
	return 0;
}