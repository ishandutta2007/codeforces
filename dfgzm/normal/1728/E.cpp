//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=3e5+5;
const ll inf=1e18;
int a[maxn],b[maxn];
ll s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll p,q;
int exgcd(int x,int y){
	if(y==0){
		p=1,q=0;
		return x;
	}
	int g=exgcd(y,x%y);
	ll tmp=p;
	p=q,q=tmp-q*(x/y);
	return g;
}
int main(){
    int n;
	n=read();
	ll sum=0;
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read()-a[i],sum+=a[i];
	sort(b+1,b+n+1);reverse(b+1,b+n+1);
	int pos=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+b[i];
		if(b[i]>=0)pos=i;
	}
	int m;
	m=read();
	for(int i=1;i<=m;i++){
		ll res=-inf;
		ll x,y;
		x=read();y=read();
		ll g=exgcd(x,y);
		if(n%g){puts("-1");continue;}
//		cerr<<p<<" "<<q<<endl;
		p*=n/g,q*=n/g;
		ll u=y/g,v=x/g;
		if(p<0){
			ll k=(-p+u-1)/u;
			p+=k*u;q-=k*v;
			if(q<0){puts("-1");continue;}
		}
		if(q<0){
			ll k=(-q+v-1)/v;
			q+=k*v,p-=k*u;
			if(p<0){puts("-1");continue;}
		}
//		cerr<<p<<" "<<q<<endl;
		if(q*y==pos)res=max(res,s[pos]);
		else if(q*y<pos){
			ll k=min((pos-q*y)/(v*y),p/u);
			res=max(res,s[(q+k*v)*y]);
			if(k!=p/u)res=max(res,s[(q+k*v+v)*y]);
		}
		else{
			ll k=(q*y-pos)/(v*y);
			res=max(res,s[(q-k*v)*y]);
			if(q-k*v-v>=0)res=max(res,s[(q-k*v-v)*y]);
		}
		if(res==-inf)puts("-1");
		else printf("%lld\n",sum+res);
	}
    return 0;
}