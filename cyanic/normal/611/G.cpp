#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef long long ll;
 
const int N=1000005;
const int mod=1e9+7;
struct point{
	int x,y;
	inline friend ll operator * (point a,point b){
		return 1ll*a.x*b.y-1ll*a.y*b.x;
	}
}p[N];
ll sx[N],sy[N],s[N],ans,sum,area;
int n;
 
inline ll getS(int l,int r){
	return s[r]-s[l]+(p[r]*p[l]);
}
inline int chk(int l,int r){
	ll L=getS(l,r),R=getS(r,l+n);
	if(L<R)return 1;
	if(L==R&&r<=n)return 1;
	return 0;
}
inline ll cro(int k,int l,int r){
	ll xy=(sx[r]-sx[l-1])*p[k].y;
	ll yx=(sy[r]-sy[l-1])*p[k].x;
	return (xy%mod-yx%mod+mod)%mod;
}
 
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
	rep(i,1,n/2)swap(p[i],p[n+1-i]);
	rep(i,1,n)p[i+n]=p[i];p[0]=p[n];
	REP(i,n)area=(area+(p[i]*p[i+1]))%mod;
	sx[0]=p[0].x,sy[0]=p[0].y;
	rep(i,1,2*n){
		sx[i]=(sx[i-1]+p[i].x)%mod;
		sy[i]=(sy[i-1]+p[i].y)%mod;
		s[i]=s[i-1]+(p[i-1]*p[i]);
	}
	int r=0;
	rep(l,1,n){
		if(r<=l+1)sum=0,r=l+1;
		while(chk(l,r+1))sum=(sum+s[++r]-s[l]+mod)%mod;
		ans=(ans+sum+cro(l,l+2,r))%mod;
		sum=(sum-(p[l]*p[l+1])%mod*(r-l-1)%mod
			-(p[l+1]*p[l+2])%mod+2ll*mod)%mod;
	}
	ans=(1ll*n*(n-3)/2)%mod*area-2*ans;
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}