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
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
ll n,m,k,a,b,ans;
vector<ll> x[N],y[N];

struct node{
	ll x,y;
	friend bool operator < (node a,node b){return a.y<b.y;}
}v[N];

void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}
ll getinv(ll a,ll mod){
	ll x,y;exgcd(a,mod,x,y);
	return (x+mod)%mod;
}

ll solve(ll x,ll y,vector<ll> &X,vector<ll> &Y){
	if(x==1)return 0;
	vector<ll> a;
	unordered_map<ll,int> mark;
	for(auto t:X)a.pb(t),mark[t]=1;
	for(auto t:Y)a.pb(t);
//	puts("------------------------");
//	cout<<"#"<<x<<"  "<<y<<endl<<"@ ";
//	for(auto t:a)cout<<t<<" ";cout<<endl;
	unordered_map<ll,ll> app;
	for(auto t:a)app.count(t%x)?app[t%x]=min(app[t%x],t):app[t%x]=t;
	for(auto &t:a)app[t%x]==t?app[t%x]=-1:t=-1;
	sort(a.begin(),a.end(),greater<ll>());
	while(!a.empty()&&a.back()==-1)a.pop_back();
	ll inv=getinv(y,x),cnt=0,res=0;
	for(auto t:a)v[++cnt]=(node){t,t*inv%x};
	sort(v+1,v+cnt+1),v[cnt+1]=v[1],v[cnt+1].y+=x;
	rep(i,1,cnt)
		if(v[i].y+1<v[i+1].y||!mark[v[i].x])
			res=max(res,(v[i+1].y-v[i].y-1)*y+v[i].x);
//	rep(i,1,cnt+1)printf("$  %lld  %lld\n",v[i].x,v[i].y);
//	cout<<"res = "<<res<<endl;
	return res;
}

int main(){
	read(n),read(m),k=__gcd(n,m),n/=k,m/=k;
	if(k>=N)return puts("-1"),0;
	for(read(a);a--;)read(b),x[b%k].pb(b/k);
	for(read(a);a--;)read(b),y[b%k].pb(b/k);
	REP(i,k)if(x[i].empty()&&y[i].empty())return puts("-1"),0;
	else{
		ll A=(x[i].size()==n?0:solve(n,m,x[i],y[i])*k+i);
		ll B=(y[i].size()==m?0:solve(m,n,y[i],x[i])*k+i);
		ans=max(ans,max(A,B));
	}
	return cout<<ans<<endl,0;
}