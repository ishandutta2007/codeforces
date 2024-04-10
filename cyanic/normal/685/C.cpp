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

const ll op[4][3]={{1,1,1},{-1,1,1},{1,-1,1},{1,1,-1}};
const ll tt=1e9,inf=3*tt*tt,lim=tt*tt;
const int N=100005;
ll mn[4],mx[4],p[4][2],res[4];
ll x[N],y[N],z[N];
int n,ty;

bool ins(ll x){
	return -lim<=x&&x<=lim;
}

bool judge(ll val){
	rep(i,1,3){
		ll L=mn[i],R=mx[i];
		if((L&1)!=(val&1))L++;
		if((R&1)!=(val&1))R--;
		if(L>R)return 0;
		p[i][0]=L,p[i][1]=R;
	}
//	cerr<<"@"<<val<<endl;
//	rep(i,1,3)cout<<p[i][0]<<"   "<<p[i][1]<<endl;
	rep(i,1,3)rep(j,i+1,3)
		REP(u,2)REP(v,2){
			ll a=p[i][u],b=p[j][v],c=val-p[i][u]-p[j][v];
			if(p[6-i-j][0]<=c&&c<=p[6-i-j][1]){
				res[i]=a,res[j]=b,res[6-i-j]=c;
				return 1;
			}
		}
	return 0;
}
/*
1
2
-145255766706388757 476404615552177224 -999765562954824823
-380327607505445243 -699203514893839424 -810739283691155327
*/
ll fix(ll x){
	return max(-inf,min(inf,x));
}

bool chk(ll d){
	REP(i,4)
		mn[i]=-inf,mx[i]=inf;
	rep(i,1,n)REP(j,4){
		ll A=
		mn[j]=max(mn[j],x[i]*op[j][0]+y[i]*op[j][1]+z[i]*op[j][2]-d);
		mx[j]=min(mx[j],x[i]*op[j][0]+y[i]*op[j][1]+z[i]*op[j][2]+d);
	}
	if((ld)mn[1]+mn[2]+mn[3]>-4e18)
		mn[0]=max(mn[0],mn[1]+mn[2]+mn[3]);
	if((ld)mx[1]+mx[2]+mx[3]<4e18)
		mx[0]=min(mx[0],mx[1]+mx[2]+mx[3]);
//	puts("----------");
//	printf("## : %lld\n",d);
//	REP(k,4) cout<<mn[k]<<"  "<<mx[k]<<endl;
	for(ll i=mn[0];i<=mn[0]+2&&i<=mx[0];i++)
		if(judge(i))return 1;
	for(ll i=mx[0];i>mn[0]+2&&i>=mx[0]-2&&i>=mn[0];i--)
		if(judge(i))return 1;
	return 0;
}

void rmain(){
	read(n);
	rep(i,1,n)
		read(x[i]),read(y[i]),read(z[i]);
	ll l=0,r=inf,mi; ty=0;
	while(l<r){
		mi=(l+r)>>1;
		if(chk(mi))r=mi;
		else l=mi+1;
	}
	ty=1,chk(l);
	ll X=(res[2]+res[3])/2;
	ll Y=(res[1]+res[3])/2;
	ll Z=(res[1]+res[2])/2;
	printf("%lld %lld %lld\n",X,Y,Z);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}