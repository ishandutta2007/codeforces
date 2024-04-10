#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005;
ll a[N],s[N],q[N],p[N],l,r,n;

ld val(ll i,ll j){
	return (ld)(s[i]-s[j])/(i-j);
}
ll cro(ll X1,ll Y1,ll X2,ll Y2){
	return X1*Y2-X2*Y1;
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	per(i,n,1){
		while(r-l>=2&&cro(q[r-2]-i,s[q[r-2]]-s[i],
						  q[r-1]-i,s[q[r-1]]-s[i])>=0) r--;
		q[r++]=i;
		int le=l,ri=r-1,lm,rm;
		ld best=1e9;
		while(ri-le>=4){
			lm=(le+le+ri)/3;
			rm=(le+ri+ri)/3;
			ld lf=val(q[lm],i-1);
			ld rf=val(q[rm],i-1);
			if(lf>rf) le=lm;
			else ri=rm;
		}
		rep(j,le,ri){
			ld now=val(q[j],i-1);
			if(now<best) best=now,p[i]=q[j];
		}
	}
	int now=1;
	while(now<=n){
		int nxt=p[now];
		ld v=val(nxt,now-1);
		rep(i,now,nxt) printf("%.10lf\n",double(v));
		now=nxt+1;
	}
	return 0;
}