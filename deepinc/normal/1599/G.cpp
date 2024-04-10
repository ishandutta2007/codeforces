#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)(x);i<=(ll)(y);++i)
#define rep(i,x,y)	for(ll i=(ll)(x);i<(ll)(y);++i)
#define FOr(i,x,y)	for(ll i=(ll)(x);i>=(ll)(y);--i)
#define pa pair<ll,ll>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define y1 yeeeeeeeeeeeeee
ll read(){
	ll x;scanf("%lld",&x);
	return x;
}
const ll N=200010;
struct point{
	ll x,y;
}p[N],b[N];
long double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool operator <(point a,point b){
	return (a.x==b.x)?(a.y<b.y):(a.x<b.x);
}
ll n,m,k,teshu;
ll cha(ll x1,ll y1,ll x2,ll y2){
	return x1*y2-x2*y1;
}
ll count(ll x,ll y){
	ll sum=0;
	For(i,1,n)if (i!=x&&i!=y){
		if (cha(p[i].x-p[x].x,p[i].y-p[x].y,p[i].x-p[y].x,p[i].y-p[y].y)==0)++sum;
		else	teshu=i;
	}
	return sum;
}
int main(){
	n=read();	k=read();
	For(i,1,n)	p[i].x=read(),p[i].y=read();
	if(count(1,2)!=n-3){
		if(count(1,3)!=n-3){
			if(count(2,3)!=n-3){
			}
		}
	}
	long double ans=1e18;
	if (k==teshu){
		For(i,1,n)if (i!=k&&i!=teshu)b[++m]=p[i];
		sort(b+1,b+m+1);
		ans=min(dist(b[1],p[teshu]),dist(b[m],p[teshu]))+dist(b[1],b[m]);
	}else{
		For(i,1,n)if (i!=k&&i!=teshu)b[++m]=p[i];
		sort(b+1,b+m+1);
		ans=min(dist(b[1],p[teshu]),dist(b[m],p[teshu]))+dist(p[k],p[teshu])+dist(b[1],b[m]);
		for (int i=1;i<m;++i){
		    ans=min(ans,dist(p[k],b[1])+dist(b[1],b[i])+dist(b[i],p[teshu])+dist(p[teshu],b[i+1])+dist(b[i+1],b[m]));
		}
		for (int i=2;i<=m;++i){
		    ans=min(ans,dist(p[k],b[m])+dist(b[m],b[i+1])+dist(b[i+1],p[teshu])+dist(p[teshu],b[i])+dist(b[i],b[1]));
		}
		ll L=0,R=0;
		For(i,1,m)if(b[i]<p[k])	L=i;
		FOr(i,m,1)if(p[k]<b[i])	R=i;
		if (L)ans=min(ans,dist(p[k],b[1])+dist(b[1],p[teshu])+(R?(dist(b[R],b[m])+min(dist(b[R],p[teshu]),dist(b[m],p[teshu]))):0)); 
		if (R)ans=min(ans,dist(p[k],b[m])+dist(b[m],p[teshu])+(L?(dist(b[L],b[1])+min(dist(b[L],p[teshu]),dist(b[1],p[teshu]))):0));
		ans=min(ans,dist(b[1],p[k])+dist(b[1],b[m])+dist(b[m],p[teshu]));
		ans=min(ans,dist(b[m],p[k])+dist(b[1],b[m])+dist(b[1],p[teshu]));
	}
	printf("%.10lf\n",(double)ans);
}