#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e3+10;

ll n,p,w,d;

ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
void Exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) x=1,y=0;
	else Exgcd(b,a%b,y,x),y-=a/b*x;
}



int main(){
	cin>>n>>p>>w>>d;
	int fl=1;
	if(w>d) {
		swap(w,d);
		fl=1;
	}
	ll g=gcd(d,w);
	if(p%g) return puts("-1"),0;
	p/=g,w/=g,d/=g;
	ll x,y;
	Exgcd(w,d,x,y);
	x%=d;
	x=x*(p%d)%d;
	x=(x%d+d)%d;
	y=(p-w*x)/d;
	//cout<<"#"<<x<<' '<<y<<endl;
	if(x>=0 && y>=0 && x+y<=n) {
		if(fl) swap(x,y);
		cout<<x<<' '<<y<<' '<<n-x-y<<endl;
	}
	else puts("-1");
}