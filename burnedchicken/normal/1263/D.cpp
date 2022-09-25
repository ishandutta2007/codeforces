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
int n,ans=0;
bool used[maxn][26]={false};
string str[maxn];
vector<int> vec;
set<int> st;

int father[maxn];
void init(){rep(maxn) father[i]=i;}
int find(int n){return n==father[n]?n:(father[n]=find(father[n]));}
void Union(int a, int b){
	int tmp1=find(a),tmp2=find(b);
	if(tmp1==tmp2) return;
	father[tmp2]=tmp1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> str[i];
	rep(n) rep1(j,str[i].size()) used[i][str[i][j]-'a']=true;
	init();
	rep(26){
		vec.clear();
		rep1(j,n) if(used[j][i]) vec.pb(j);
		rep1(j,int(vec.size())-1) Union(vec[j],vec[j+1]);
	}
	rep(n) st.insert(find(i));
	print1(st.size());
	return 0;
}