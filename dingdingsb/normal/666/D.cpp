#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define ve vector
typedef pair<int,int> pii;
int T;pii p[4];
tuple<int,pii,pii,pii,pii>ans;
//[]
int calc(int i,pii a){
	if(p[i].fi==a.fi||p[i].se==a.se)return abs(p[i].fi-a.fi)+abs(p[i].se-a.se);
	return 0x3f3f3f3f;
}
void upd(int x,int y,int l){
	if(!l)return;
	ve<pii>p={mp(x,y),mp(x+l,y),mp(x,y+l),mp(x+l,y+l)};
	int a[4];iota(a,a+4,0);
	do{
		int res=max(max(calc(0,p[a[0]]),calc(1,p[a[1]])),max(calc(2,p[a[2]]),calc(3,p[a[3]])));
		if(res<=1e9)chkmn(ans,mt(res,p[a[0]],p[a[1]],p[a[2]],p[a[3]]));
	}while(next_permutation(a,a+4));
}
void upd(ve<pii>ls){
	//0 =  1=
	sort(ls.begin(),ls.end());
	if(ls[0].fi==0&&ls[1].fi==0&&ls[2].fi==0&&ls[3].fi==0){
		if(ls[0].se==ls[1].se&&ls[2].se==ls[3].se){
			int l=ls[2].se-ls[0].se;
			if(l){
				vector<int>arr[2],fl;
				for(int i=0;i<4;i++)if(p[i].se==ls[0].se)arr[0].pb(p[i].fi);else arr[1].pb(p[i].fi);
				fl.pb(min(arr[0][0],arr[0][1]));fl.pb(max(arr[0][0],arr[0][1])-l);
				fl.pb(min(arr[1][0],arr[1][1]));fl.pb(max(arr[1][0],arr[1][1])-l);
				sort(fl.begin(),fl.end());
				upd((fl.front()+fl.back())/2,ls[0].se,l);
			}
		}
	}
	if(ls[0].fi==0&&ls[1].fi==0&&ls[2].fi==0&&ls[3].fi==1){
		if(ls[1].se==ls[0].se||ls[1].se==ls[2].se){
			int l=ls[2].se-ls[0].se;
			upd(ls[3].se,ls[0].se,l);
			upd(ls[3].se-l,ls[0].se,l);
		}
	}
	if(ls[0].fi==0&&ls[1].fi==0&&ls[2].fi==1&&ls[3].fi==1){
		int l;
		l=ls[3].se-ls[2].se;
		for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++)upd(ls[2].se+i*l,ls[0].se+j*l,l);
		l=ls[1].se-ls[0].se;
		for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++)upd(ls[2].se+i*l,ls[0].se+j*l,l);
	}
	if(ls[0].fi==0&&ls[1].fi==1&&ls[2].fi==1&&ls[3].fi==1){
		if(ls[1].se==ls[2].se||ls[2].se==ls[3].se){
			int l=ls[3].se-ls[1].se;
			upd(ls[1].se,ls[0].se,l);
			upd(ls[1].se,ls[0].se-l,l);
		}
	}
	if(ls[0].fi==1&&ls[1].fi==1&&ls[2].fi==1&&ls[3].fi==1){
		if(ls[0].se==ls[1].se&&ls[2].se==ls[3].se){
			int l=ls[2].se-ls[0].se;
			if(l){
				vector<int>arr[2],fl;
				for(int i=0;i<4;i++)if(p[i].fi==ls[0].se)arr[0].pb(p[i].se);else arr[1].pb(p[i].se);
				fl.pb(min(arr[0][0],arr[0][1]));fl.pb(max(arr[0][0],arr[0][1])-l);
				fl.pb(min(arr[1][0],arr[1][1]));fl.pb(max(arr[1][0],arr[1][1])-l);
				sort(fl.begin(),fl.end());
				upd(ls[0].se,(fl.front()+fl.back())/2,l);
				
			}
		}
	}
}
signed main(){
	read(T);
	for(int SJYAK=1;SJYAK<=T;SJYAK++){
		ans=mt(0x3f3f3f3f,mp(0,0),mp(0,0),mp(0,0),mp(0,0));
		for(int i=0;i<4;i++)read(p[i].fi,p[i].se);
		for(int S=0;S<(1<<4);S++){
			ve<pii>ls;
			for(int i=0;i<4;i++)
				if(S>>i&1)ls.eb(1,p[i].fi);
				else ls.eb(0,p[i].se);
			upd(ls);
		}
		pii A,B,C,D;
		int dis;tie(dis,A,B,C,D)=ans;
		if(dis==0x3f3f3f3f)writeln(-1);
		else writeln(dis),writeln(A.fi,A.se),writeln(B.fi,B.se),writeln(C.fi,C.se),writeln(D.fi,D.se);
	}
	cerr<<"";
}