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
#define orz puts("NO"),exit(0)
const int N=4e6+100;
typedef long double ld;
int n,l;ll t[N],x[N],y[N];
void solve(map<int,pair<ll,ll>>&pos){
	string ans;
	for(auto X:pos)if((X.fi+X.se.fi+X.se.se)&1)orz;
	for(auto it=pos.begin();it->fi!=l;it++){
		pair<ll,ll>now=it->se,nxt=next(it)->se;
		int cnt=(next(it)->fi)-(it->fi);
		if(abs(now.fi-nxt.fi)+abs(now.se-nxt.se)>cnt)orz;
		while(now.fi!=nxt.fi){
			if(now.fi<nxt.fi)now.fi++,ans+='R';
			else now.fi--,ans+='L';
			cnt--;
		}
		while(now.se!=nxt.se){
			if(now.se<nxt.se)now.se++,ans+='U';
			else now.se--,ans+='D';
			cnt--;
		}
		assert(cnt>=0&&cnt%2==0);
		while(cnt)ans+="UD",cnt-=2;
	}
	cout<<ans;
	exit(0);
}
void chk(){
	map<ll,int>id;id[0]=0;
	for(int i=1;i<=n;i++){
		if(id.count(t[i]%l)){
			int j=id[t[i]%l];
			if((x[i]-x[j])%((t[i]-t[j])/l))orz;
			if((y[i]-y[j])%((t[i]-t[j])/l))orz;
			ll deltaX=(x[i]-x[j])/((t[i]-t[j])/l);
			ll deltaY=(y[i]-y[j])/((t[i]-t[j])/l);
			if(abs(deltaX)>l||abs(deltaY)>l)orz;
			map<int,pair<ll,ll>>pos;
			pos[0]=mp(0,0);pos[l]=mp(deltaX,deltaY);
			for(int i=1;i<=n;i++){
				ll cts=(t[i]-1)/l;
				if(pos.count((t[i]-1)%l+1))if(pos[(t[i]-1)%l+1]!=mp(x[i]-cts*deltaX,y[i]-cts*deltaY))orz;
				pos[(t[i]-1)%l+1]=mp(x[i]-cts*deltaX,y[i]-cts*deltaY);
			}
			solve(pos);
		}
		id[t[i]%l]=i;
	}
}
bool vis[2][2];
bool can[2][2];
signed main(){
	read(n,l);
	for(int i=1;i<=n;i++)read(t[i],x[i],y[i]);
	chk();// x y 
	// l 
	map<int,tuple<ll,ll,ll>>m;
	// (a,b,c) (a dx + b,a dy + c)
	m[0]=mt(0,0,0);m[l]=mt(1,0,0);
	for(int i=1;i<=n;i++){
		ll cts=(t[i]-1)/l;
		m[t[i]%l]=mt(-cts,x[i],y[i]);
	}
	ld A=-1e24,B=1e24,C=-1e24,D=1e24;
	auto addrule=[&](ll a,ll b,ll c){
		// add a x + b y <= c
		assert(abs(a)==abs(b));
		if(!a){
			if(c<0)orz;
			return;
		}
		if(a==b){
			if(a>0)chkmn(B,(ld)c/a);
			else chkmx(A,(ld)c/a);
		}else{
			if(a>0)chkmn(D,(ld)c/a);
			else chkmx(C,(ld)c/a);
		}
	};
	for(auto X:m)vis[get<0>(X.se)&1][(get<1>(X.se)+get<2>(X.se)+X.fi)&1]=1;
	for(auto it=m.begin();it->fi!=l;it++){
		//|(get<0>(it->se)-get<0>(next(it)->se))x+get<1>(next(it)->se)-get<1>(it->se)|+
		//|(get<0>(it->se)-get<0>(next(it)->se))y+get<2>(next(it)->se)-get<2>(it->se)|<=next(it)->fi-it->fi
		ll a=get<0>(it->se)-get<0>(next(it)->se);
		ll b=get<1>(next(it)->se)-get<1>(it->se);
		ll c=get<2>(next(it)->se)-get<2>(it->se);
		ll d=(next(it)->fi)-(it->fi);
		// | a dx + b | + | a dy + c | <= d
		addrule(a,a,d-b-c);
		addrule(a,-a,d-b+c);
		addrule(-a,a,d+b-c);
		addrule(-a,-a,d+b+c);
	}
	memset(can,1,sizeof can);
	for(int x=0;x<2;x++)for(int y=0;y<2;y++){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)
			if(vis[i][j]&&(x*i+y*i+j)%2)can[x][y]=0;
	}
	for(int dx=-l;dx<=l;dx++){
		ll st=ceil(max(A-dx,dx-D));
		ll ed=floor(min(B-dx,dx-C));
		if(st<=ed){
			for(int dy=st;dy<=min(st+1,ed);dy++)if(can[dx&1][dy&1]){
				map<int,pair<ll,ll>>pos;
				for(auto X:m)pos[X.fi]=mp(get<1>(X.se)-get<0>(X.se)*dx,get<2>(X.se)-get<0>(X.se)*dy);
				solve(pos);
			}
		}
	}
	orz;
}