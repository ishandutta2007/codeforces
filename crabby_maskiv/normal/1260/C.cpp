#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=0x3f3f3f3f;
int n,m;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int i,j;
	int T;scanf("%d",&T);
	while(T--){
		ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
		if(x<y) swap(x,y);
		ll g=gcd(x,y);
		x/=g;y/=g;
		ll w;
		if(x%y==0) w=x/y-1;
		else{
			if(x%y==1) w=x/y;
			else w=x/y+1;
		}
		if(w>=z) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}