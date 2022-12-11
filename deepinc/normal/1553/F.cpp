#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c[333333];ll s[333333],t,ans;
void addc(int p){while(p<=300000)c[p]++,p+=p&-p;}
int askc(int p,int a=0){while(p)a+=c[p],p-=p&-p;return a;}
void adds(int p,int v){while(p<=300000)s[p]+=v,p+=p&-p;}
ll asks(int p,ll a=0){while(p)a+=s[p],p-=p&-p;return a;}
int main(){
	scanf("%d",&n);for(int T=1;T<=n;++T){
		int a; scanf("%d",&a);
		ans+=t;
		for(int x=a-1,l=0,r=0;x<=300000+a;x+=a)r=askc(min(x,300000)),ans-=(r-l)*(x+1ll-a),l=r;
		ans+=a*(T-1ll); ll la=0,ra=0; 
		for(int l=1,r=0,d;r<a;l=r+1)d=a/l,r=a/d,ra=asks(r),ans-=d*(ra-la),la=ra;
		t+=a; addc(a); adds(a,a); printf("%lld ",ans);
	}
}