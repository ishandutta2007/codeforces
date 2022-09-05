#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
ll n,k;map<ll,ll>Map;
ll tar,need;
inline ll getcnt(ll n, ll tar){
	ll res=0,val=n,x=0,y=1;
	while(val){
	//	printf("%lld %lld %lld\n",val,x,y);
		res+=(val>1&&(val-2)/2==tar?x:0)+((val-1)/2==tar?y:0);
		if(val==1)break;
		ll a=0,b=0;
		if(val/2==val/2)b+=y;else a+=y;
		if((val-1)/2==val/2)b+=y+x;else a+=y+x;
		if((val-2)/2==val/2)b+=x;else a+=x;
		val/=2;x=a;y=b;
	}
	return res;
}
ll getans(ll n, ll tar, ll need){
	if(n==1)return n;
	if((n-1)/2==tar)need--;if(!need)return (n+1)/2;
	ll zuo=getcnt((n-1)/2,tar);
//	printf("%lld %lld %lld %lld %lld\n",n,tar,need,(n-1)/2,zuo);
	if(zuo>=need)return getans((n-1)/2,tar,need);
	return getans(n/2,tar,need-zuo)+(n-1)/2+1;
}
int main() {
//	printf("%lld\n",getcnt(24,5));return 0;
	
	read(n);read(k);
	if(k==1){printf("1\n");return 0;}
	if(k==2){printf("%lld\n",n);return 0;}
	Map[n-2]++;ll lst=k-2;
	while(Map.size()){
		ll x=(*Map.rbegin()).fi,cnt=(*Map.rbegin()).se;
		if(!cnt){Map.erase(--Map.end());continue;}
		ll cur=(*Map.rbegin()).se+(x%2==0?Map[x-1]:0)+(x==2?cnt:0);
	//	printf("ans %lld %lld %lld %lld\n",x,cnt,cur,lst);
		Map[x/2]+=cnt;Map[(x-1)/2]+=cnt;
		if(cur<lst){
			lst-=cnt;Map.erase(--Map.end());
		}
		else{
			tar=(x-1)/2;need=lst;break;
		}
	}
//	printf("qwq %lld %lld\n",tar,need);
//	rep(i,1,n-2)printf("%d:%lld\n",i,getcnt(i,tar));
	printf("%lld\n",getans(n-2,tar,need)+1);
	return 0;
}