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
 
const int maxn=1000005;
//i_am_noob
int n,w,tel[maxn]={0},l,a[maxn],maxx,ans=0;
deque<int> dq;
bool flag;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> w;
	while(n--){
		cin >> l;
		rep(l) cin >> a[i];
		if(2*l>=w){
			while(!dq.empty()) dq.pop_back();
			rep(w){
				if(!dq.empty()) if(i-dq.front()>w-l) dq.pop_front();
				if(i<l) while(1){
					flag=false;
					if(dq.empty()) flag=true;
					else if(a[dq.back()]>a[i]) flag=true;
					if(flag){
						dq.pb(i);
						break;
					}
					dq.pop_back();
				}
				if(i<w-l||i>=l) tel[i]+=max(0ll,a[dq.front()]),tel[i+1]-=max(0ll,a[dq.front()]);
				else tel[i]+=a[dq.front()],tel[i+1]-=a[dq.front()];
			}
		}
		else{
			maxx=0;
			rep(l){
				maxx=max(maxx,a[i]);
				tel[i]+=maxx,tel[i+1]-=maxx;
			}
			maxx=0;
			rep3(i,w-1,w-l){
				maxx=max(maxx,a[i-w+l]);
				tel[i]+=maxx,tel[i+1]-=maxx;
			}
			tel[l]+=maxx,tel[w-l]-=maxx;
		}
	}
	rep(w){
		ans+=tel[i];
		print0(ans);
	}
	cout << '\n';
	return 0;
}