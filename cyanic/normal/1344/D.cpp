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
typedef long double ld;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int a[N],x[N],n;
ll l,r,K;

ll calc(ll t){
	ll sum=0;
	rep(i,1,n){
		ld A=3,B=4,C=1-a[i]+t;
		ld delta=B*B-4*A*C;
		ll tmp=(-B+sqrt(delta))/A/2;
		x[i]=max(0ll,min((ll)a[i],tmp+1));
		sum+=x[i];
	}
	return sum;
}

int main(){
	read(n),read(K);
	rep(i,1,n) read(a[i]);
	l=-4e18,r=3e9;
	while(l<r){
		ll m=(l+r)/2;
		if(r-l<=1) m=l;
		if(calc(m)<=K) r=m;
		else l=m+1;
	}
	ll rem=K-calc(l),mx=-4e18;
	rep(i,1,n) if(x[i]<a[i]){
		mx=max(mx,a[i]-3ll*x[i]*x[i]-4ll*x[i]-1);
	}
	rep(i,1,n) if(x[i]<a[i]&&rem){
		if(mx==a[i]-3ll*x[i]*x[i]-4ll*x[i]-1){
			rem--,x[i]++;
		}
	}
	rep(i,1,n) printf("%d ",x[i]);
	return 0;
}