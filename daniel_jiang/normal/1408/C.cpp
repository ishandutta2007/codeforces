// wish to get better qwq
#include<bits/stdc++.h>
#define RE register int
using namespace std;
typedef long long ll;
const ll N=2e5+51,MOD=998244353,inf=0x3f3f3f3f;
ll t,n,len,x[N];
double l,r,mid;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
inline ll check(double mid){
	double qaq=0,v=1,t=mid,p;
	for(RE i=1;i<=n+1;i++){
		p=(x[i]-x[i-1])/v;
		if(p<=t) qaq=x[i],t-=(x[i]-x[i-1])/v,v++;
		else{qaq+=v*t;break;}
	}
	double qwq=len;
	v=1,t=mid;
	for(RE i=n;i>=0;i--){
		p=(x[i+1]-x[i])/v;
		if(p<=t) qwq=x[i],t-=(x[i+1]-x[i])/v,v++;
		else{qwq-=v*t;break;}
	}
	return qaq>=qwq;
}
inline void solve(){
	rd(n),rd(len);
	for(RE i=1;i<=n;i++) rd(x[i]);
	x[0]=0,x[n+1]=len,l=0.0,r=len+5;
	for(RE i=1;i<=90;i++)mid=(l+r)/2.0,check(mid)?r=mid:l=mid;
	printf("%.12lf\n",l);
}
int main(){
	rd(t);
	for(RE i=0;i<t;i++) solve();
	return 0;
}