#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
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
const ll MOD=Mod2;
 
ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
ll v2(ll n){return ((n&1)?0:v2(n>>1)+1);}
 
const int maxn=200005;
//i_am_noob
int t,n,x=0,y=0;
string str[maxn];
vector<int> vec[2];
bool b[2];
set<string> st;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		rep(n) cin >> str[i];
		rep(2) vec[i].clear(),b[i]=false;
		st.clear();
		rep(n){
			if(str[i][0]=='0'&&str[i][sz(str[i])-1]=='1') vec[0].pb(i);
			if(str[i][0]=='1'&&str[i][sz(str[i])-1]=='0') vec[1].pb(i);
			if(str[i][0]=='0'&&str[i][sz(str[i])-1]=='0') b[0]=true;
			if(str[i][0]=='1'&&str[i][sz(str[i])-1]=='1') b[1]=true;
		}
		if(vec[0].empty()&&vec[1].empty()&&b[0]&&b[1]){
			print1(-1);
			continue;
		}
		if(sz(vec[0])<sz(vec[1])) swap(vec[0],vec[1]);
		rep(sz(vec[1])) st.insert(str[vec[1][i]]);
		print1(sz(vec[0])-sz(vec[1])>>1);
		x=y=0;
		while(x<sz(vec[0])-sz(vec[1])>>1){
			reverse(all(str[vec[0][y]]));
			if(!st.count(str[vec[0][y]])){
				print0(vec[0][y]+1);
				x++;
			}
			y++;
		}
		cout << '\n';
	}
	return 0;
}