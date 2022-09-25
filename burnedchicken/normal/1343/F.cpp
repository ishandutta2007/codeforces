#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=205;
//i_am_noob
int t,n,p[maxn],l[maxn],k,x,y;
vector<int> vec[maxn];
set<int> st[maxn];
bool ok;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		rep(n-1){
			vec[i].clear();
			cin >> k;
			rep1(j,k){
				cin >> x;
				vec[i].pb(x-1);
			}
		}
		rep(n){
			ok=true;
			rep1(j,n-1) st[j].clear();
			rep1(j,n-1) rep1(ii,sz(vec[j])) st[j].insert(vec[j][ii]);
			p[0]=i;
			rep1(j,n-1){
				if(st[j].count(i)&&sz(st[j])==sz(vec[j])) l[j]=0;
				st[j].erase(i);
			}
			rep2(j,1,n){
				x=0;
				rep1(ii,n-1) if(sz(st[ii])==1){
					x++;
					y=ii;
				}
				if(x!=1){
					ok=false;
					break;
				}
				if(j-l[y]+1!=sz(vec[y])){
					ok=false;
					break;
				}
				p[j]=*st[y].begin();
				rep1(ii,n-1){
					if(st[ii].count(p[j])&&sz(st[ii])==sz(vec[ii])) l[ii]=j;
					st[ii].erase(p[j]);
				}
			}
			if(ok){
				rep1(j,n) print0(p[j]+1);
				cout << '\n';
				break;
			}
		}
	}
	return 0;
}