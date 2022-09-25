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
 
const int maxn=200005;
//i_am_noob
int n,a[maxn];
ld b[maxn],cur;
stack<pair<int,ld> > sk1,sk2;

ld f(int pos1, int pos2){return (b[pos2]-b[pos1])/(pos1-pos2);}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n;
	rep(n) cin >> a[i];
	if(n==1){
		print1(0);
		return 0;
	}
	b[0]=0;
	rep(n) b[i+1]=b[i]+a[i];
	sk1.push(mp(0,-1e100));
	rep2(i,1,n+1){
		while(1){
			cur=f(sk1.top().first,i);
			if(cur>sk1.top().second-eps){
				sk1.push(mp(i,cur));
				break;
			}
			else sk1.pop();
		}
	}
	sk2.push(mp(n,-1e100));
	rep3(i,n-1,0){
		while(1){
			cur=f(i,sk2.top().first);
			if(cur>sk2.top().second-eps){
				sk2.push(mp(i,cur));
				break;
			}
			else sk2.pop();
		}
	}
	while(1){
		if(sk1.top().second<sk2.top().second){
			cur=sk2.top().second;
			sk2.pop();
			if(sk1.top().first<=sk2.top().first){
				rep(n+1) b[i]+=i*cur;
				print1((*max_element(b,b+n+1))-(*min_element(b,b+n+1)));
				return 0;
			}
		}
		else{
			cur=sk1.top().second;
			sk1.pop();
			if(sk1.top().first<=sk2.top().first){
				rep(n+1) b[i]+=i*cur;
				print1((*max_element(b,b+n+1))-(*min_element(b,b+n+1)));
				return 0;
			}
		}
	}
	return 0;
}