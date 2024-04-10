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
const int maxn=55;
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
int n,m,ans1[maxn][maxn],ans2[maxn][maxn];

int query(int a, int b, int c, int d){
	print0("?");
	print4(a+1,b+1,c+1,d+1);
	cout << flush;
	int tmp;
	cin >> tmp;
	return tmp;
}
void copy(int a, int b, int c, int d){
	if(c+d>a+b) ans1[c][d]=query(a,b,c,d)?ans1[a][b]:1-ans1[a][b];
	else ans1[c][d]=query(c,d,a,b)?ans1[a][b]:1-ans1[a][b];
	ans2[c][d]=a+b&1?1-ans1[c][d]:ans1[c][d];
	return;
}
int pretend_query(int a, int b, int c){
	if(c==1) return (ans1[a][b]==ans1[a+2][b+1])&&(ans1[a][b+1]==ans1[a+1][b+1]||ans1[a+1][b]==ans1[a+1][b+1]||ans1[a+1][b]==ans1[a+2][b]);
	else return (ans2[a][b]==ans2[a+2][b+1])&&(ans2[a][b+1]==ans2[a+1][b+1]||ans2[a+1][b]==ans2[a+1][b+1]||ans2[a+1][b]==ans2[a+2][b]);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	ans1[0][0]=ans2[0][0]=1;
	ans1[n-1][n-1]=ans2[n-1][n-1]=0;
	ans1[0][1]=0;
	ans2[0][1]=1;
	m=n>>1;
	rep(m) copy(0,2*i,0,2*i+2);
	rep(m-1) copy(0,2*i+1,0,2*i+3);
	rep2(i,1,n){
		if(i&1){
			copy(i-1,0,i,1);
			rep2(j,1,m) copy(i,2*j-1,i,2*j+1);
			copy(i-1,1,i,2);
			copy(i,2,i,0);
			rep2(j,1,m) copy(i,2*j,i,2*j+2);
		}
		else{
			copy(i-2,0,i,0);
			rep1(j,m) copy(i,2*j,i,2*j+2);
			copy(i-1,0,i,1);
			rep2(j,1,m) copy(i,2*j-1,i,2*j+1);
		}
	}
	rep(n-2){
		rep1(j,n-1){
			if(pretend_query(i,j,1)!=pretend_query(i,j,2)){
				if(query(i,j,i+2,j+1)==pretend_query(i,j,1)){
					print1("!");
					rep1(i2,n){
						rep1(j2,n) cout << ans1[i2][j2];
						cout << '\n';
					}
					cout << flush;
					return 0;
				}
				else{
					print1("!");
					rep1(i2,n){
						rep1(j2,n) cout << ans2[i2][j2];
						cout << '\n';
					}
					cout << flush;
					return 0;
				}
			}
		}
	}
	return 0;
}