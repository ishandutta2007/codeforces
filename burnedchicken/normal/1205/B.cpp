#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define printvec(a) rep(a.size()) print0(a[i])
#define debug(a) print2(#a,a)

using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=998244853;
const int maxn=100005;
/*
vector<int> prime;
bool isprime[maxn];

void find_prime(){
	isprime[0]=isprime[1]=false;
	rep2(i,2,maxn) isprime[i]=true;
	rep2(i,2,maxn){
		if(isprime[i]){
			prime.pb(i);
			int tmp=(maxn-1)/i+1;
			rep2(j,i,tmp) isprime[i*j]=false;
		}
	}
}
bool is_prime(ll n){//find_prime first,n<maxn^2
	if(n<maxn) return isprime[n];
	rep(maxn){
		if(1ll*prime[i]*prime[i]>n) break;
		if(!(n%prime[i])) return false;
	}
	return true;
}
vector<ll> prime_factors(ll n){//find_prime first
	ll m=n;
	vector<ll> ret;
	rep(maxn){
		if(m==1) break;
		ll tmp=prime[i];
		if(tmp*tmp>n) break;
		while(!(m%tmp)){
			if(ret.empty()) ret.pb(tmp);
			else if(ret.back()!=tmp) ret.pb(tmp);
			m/=tmp;
		}
	}
	if(m>1) ret.pb(m);
	return ret;
}
ll euler(ll n){
	vector<ll> vec=prime_factors(n);
	ll ret=n;
	rep(vec.size()) ret=ret/vec[i]*(vec[i]-1);
	return ret;
}
*/
//mod problem
ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
ll inverse(ll n){return Pow(n,MOD-2);}
//dgts problem
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
ll v2(ll n){return ((n&1)?0:v2(n>>1)+1);}

//i_am_noob
int n,cnt,ans=1e9,x,y,dist[maxn],father[maxn];
ll a[maxn];
vector<int> adj[maxn],vec;
bool visited[maxn];
queue<int> q;
set<pii> st;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> a[i];
	rep(64){
		cnt=0;
		vec.clear();
		rep1(j,n){
			if(a[j]&pow2(i)){
				cnt++;
				vec.pb(j);
			}
			if(cnt==3){
				print1(3);
				return 0;
			}
		}
		if(cnt==2&&!st.count(mp(vec[0],vec[1]))){
			adj[vec[0]].pb(vec[1]);
			adj[vec[1]].pb(vec[0]);
			st.insert(mp(vec[0],vec[1]));
			st.insert(mp(vec[1],vec[0]));
		}
	}
	rep(n){
		if(adj[i].size()<2) continue;
		rep1(j,n) visited[j]=false,dist[j]=1e9;
		q.push(i);
		visited[i]=true;
		dist[i]=0;
		father[i]=-1;
		while(!q.empty()){
			x=q.front();
			rep1(j,adj[x].size()){
				y=adj[x][j];
				if(visited[y]){
					if(y!=father[x]){
						ans=min(ans,dist[x]+dist[y]+1);
					}
					continue;
				}
				visited[y]=true;
				q.push(y);
				dist[y]=dist[x]+1;
				father[y]=x;
			}
			q.pop();
		}
	}
	if(ans>1e8) print1(-1);
	else print1(ans);
	return 0;
}