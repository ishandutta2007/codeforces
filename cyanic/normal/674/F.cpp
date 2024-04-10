#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned ui;
#define int ui

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

/*
p = min(p, n-1), d = n - p
f(i,j) = \sum_{k=0}^p f(i-1,j-k) C(j+d,k)

f(i,p) = \sum_{k=0}^p C(n,k) * i^k
*/

const int N=150;
ui c[N],a[N],n,p,q,ans;

ui C(ui n,ui k){
	ui res=1;
	rep(i,1,k)a[i]=n+1-i;
	rep(i,1,k){
		ui r=i;
		rep(j,1,k){
			ui t=__gcd(r,a[j]);
			r/=t,a[j]/=t;
			if(r==1)break;
		}
	}
	rep(i,1,k)res*=a[i];
	return res;
}

ui f(ui i){
	ui res=0,pw=1;
	rep(k,0,p){
		res+=c[k]*pw;
		pw*=i;
	}
	return res;	
}

signed main(){
	read(n),read(p),read(q);
	p=min(p,n-1);
	rep(i,0,p)c[i]=C(n,i);
	rep(i,1,q)ans^=i*f(i);
	cout<<ans<<endl;
	return 0;
}