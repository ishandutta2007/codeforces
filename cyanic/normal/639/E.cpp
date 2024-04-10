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
typedef double ld;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=150005;
const ld eps=1e-10;
struct node{
	int p,t; ll l,r,s;
	friend bool operator < (node a,node b){
		return (ll)a.p*b.t>(ll)a.t*b.p;
	}
	friend bool operator == (node a,node b){
		return !(a<b)&&!(b<a);
	}
	ld L(ld c){ return p*(1.0-c*l); }
	ld R(ld c){ return p*(1.0-c*r); }
}a[N];
ld pt[N],T;
int v[N],n;

bool check(ld c){
	ld mx=0,mmx=0;
	rep(i,1,n){
		if(a[i-1].p<a[i].p)mx=max(mx,mmx);
		if(mx>a[i].R(c/T))return 0;
		mmx=max(mmx,a[i].L(c/T));
	}
	return 1;
}

int main(){
	read(n);
	rep(i,1,n)read(a[i].p);
	rep(i,1,n)read(a[i].t),T+=a[i].t;
	sort(a+1,a+n+1);
	rep(i,1,n)a[i].s=a[i].r=a[i-1].s+a[i].t;
	rep(i,1,n)a[i].l=(i>1&&a[i]==a[i-1]?a[i-1].l:a[i-1].s);
	per(i,n,1)a[i].r=(i<n&&a[i]==a[i+1]?a[i+1].r:a[i].s);
	rep(i,1,n)a[i].l+=a[i].t;
	sort(a+1,a+n+1,[&](node a,node b){
		return a.p<b.p;
	});
	ld l=0,r=1,mid;
	REP(t,50){
		mid=(l+r)*0.5;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.8lf\n",(l+r)*0.5);
	return 0;
}