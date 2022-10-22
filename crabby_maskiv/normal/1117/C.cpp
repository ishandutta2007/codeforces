#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N];
ll dx,dy,sx,sy,tx,ty;
ll f(ll x){
	if(x<0) return -x;
	return x;
}
bool check(ll key){
	ll x=(key/n)*dx,y=(key/n)*dy;
	ll k=key%n;
	int i,j;
	for(i=1;i<=k;i++){
		if(a[i]=='U') y++;
		else if(a[i]=='D') y--;
		else if(a[i]=='L') x--;
		else x++;
	}
	if(f(tx-x)+f(ty-y)<=key) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>sx>>sy>>tx>>ty;
	tx-=sx;ty-=sy;
	cin>>n;
	cin>>(a+1);
	for(i=1;i<=n;i++){
		if(a[i]=='U') dy++;
		else if(a[i]=='D') dy--;
		else if(a[i]=='L') dx--;
		else dx++;
	}
	ll l=0,r=1e18;
	while(r-l>5){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	for(ll k=l;k<=r;k++){
		if(check(k)){
			cout<<k;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}