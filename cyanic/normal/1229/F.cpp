#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=35005;
const ll inf=1e18;
ll l[N],r[N],a[N],b[N],sa,ans;
int n;

ll calc(){
	priority_queue<ll,vector<ll>,greater<ll> > Qr;
	priority_queue<ll> Ql;
	ll mn=0,mx=0,pl=0,pr=0,tagl=0,tagr=0,res=0,s=0;
	Ql.push(0),Qr.push(0);
	rep(i,1,n){
		mn+=l[i],mx+=r[i];
		pl+=l[i],pr+=r[i];
		tagl+=l[i],tagr+=r[i];
		s+=a[i];
		if(s<pl){
			res+=pl-s;
			Ql.push(max(mn,s)-tagl);
			Ql.push(max(mn,s)-tagl);
			Qr.push((pr=Ql.top()+tagl)-tagr);
			Ql.pop(),pl=Ql.top()+tagl;
		}
		else if(s>pr){
			res+=s-pr;
			Qr.push(min(mx,s)-tagr);
			Qr.push(min(mx,s)-tagr);
			Ql.push((pl=Qr.top()+tagr)-tagl);
			Qr.pop(),pr=Qr.top()+tagr;
		}
		else{
			Ql.push(s-tagl),Qr.push(s-tagr);
			pl=pr=s;
		}
	}
	for(;!Ql.empty()&&s<Ql.top()+tagl;Ql.pop())
		res+=(Ql.top()+tagl)-s;
	for(;!Qr.empty()&&s>Qr.top()+tagr;Qr.pop())
		res+=s-(Qr.top()+tagr);
	return res;
}

ll solve(ll x){
	memcpy(a,b,sizeof b);
	ll bas=0;
	if(x>=0){
		ll rem=x;
		per(i,n,1){
			if(a[i]>=rem){
				bas+=(n+1-i)*rem,a[i]-=rem;
				break;
			}
			bas+=(n+1-i)*a[i],rem-=a[i],a[i]=0;
		}
		a[1]+=x;
	}
	else{
		ll rem=-x;
		rep(i,1,n){
			if(a[i]>=rem){
				bas+=i*rem,a[i]-=rem;
				break;
			}
			bas+=i*a[i],rem-=a[i],a[i]=0;
		}
		a[n]-=x;
	}
	return bas+calc();
}

int main(){
	read(n);
	rep(i,1,n){
		read(b[i]),sa+=b[i];
		read(l[i]),read(r[i]);
	}
	ll L=-sa,R=sa;
	while(R-L>3){
		ll lm=(L+R)/2,rm=lm+1;
		ll lf=solve(lm),rf=solve(rm);
		if(lf<rf) R=rm-1;
		else L=lm+1;
	}
	ans=inf;
	for(ll d=L;d<=R;d++){
		ans=min(ans,solve(d));
	}
	cout<<ans<<endl;
	return 0;
}