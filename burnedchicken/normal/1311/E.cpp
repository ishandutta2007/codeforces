#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
#define all(a) a.begin(),a.end()
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
#define debug(a) print2(#a,a)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

inline ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
inline ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
inline ll v2(ll n){return __builtin_ctzll(n);}

const int maxn=5005;
//i_am_noob
int t,n,d,cnt[maxn],x,y,z,xx,ans[maxn];
bool ok;
ordered_set ost;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> d;
		cnt[0]=1;
		x=n-1,y=0;
		ok=true;
		rep(n){
			if(x>cnt[i]*2){
				cnt[i+1]=cnt[i]*2;
				x-=cnt[i]*2;
				y+=(i+1)*cnt[i+1];
				if(y>d){
					ok=false;
					break;
				}
			}
			else{
				cnt[i+1]=x;
				y+=(i+1)*cnt[i+1];
				if(y>d){
					ok=false;
					break;
				}
				rep2(j,i+2,n) cnt[j]=0;
				break;
			}
		}
		if(!ok){
			print1("NO");
			continue;
		}
		while(y<d){
			ok=false;
			rep3(i,n-1,2){
				if(cnt[i-1]>0&&cnt[i]+1<=(cnt[i-1]-1)*2){
					cnt[i-1]--,cnt[i]++,y++;
					ok=true;
					break;
				}
			}
			if(!ok) break;
		}
		if(!ok){
			print1("NO");
			continue;
		}
		x=0,y=1,z=0,xx=cnt[1];
		ok=true;
		rep2(i,1,n){
			if(!xx){
				z+=cnt[y-1];
				x=z;
				ok=true;
				y++;
				xx=cnt[y];
			}
			if(ok){
				ans[i]=x;
				ok=false;
			}
			else{
				ans[i]=x;
				x++;
				ok=true;
			}
			xx--;
		}
		print1("YES");
		rep2(i,1,n) print0(ans[i]+1);
		cout << '\n';
	}
	return 0;
}