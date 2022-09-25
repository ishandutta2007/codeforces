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
 
const int maxn=100005;
//i_am_noob
int n,q,a,b,y,fact[70],invfact[70];
vector<int> vec1,vec2;
map<int,int> cnt,ans;

void solve(int x){
	if(x==1){
		cnt[1]=0;
		ans[1]=1;
		return;
	}
	int tmp=0,p,z=x;
	rep2(i,2,4e18){
		if(i*i>z){
			tmp=1,p=x;
			break;
		}
		if(z%i==0){
			p=i;
			while(z%i==0){
				tmp++;
				z/=i;
			}
			break;
		}
	}
	cnt[x]=cnt[x/p]+1;
	ans[x]=ans[x/p]*invfact[cnt[x/p]]%MOD*fact[cnt[x]]%MOD*fact[tmp-1]%MOD*invfact[tmp]%MOD;
	return;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	fact[0]=invfact[0]=1;
	rep2(i,1,70){
		fact[i]=fact[i-1]*i%MOD;
		invfact[i]=inverse(fact[i]);
	}
	cin >> n >> q;
	rep2(i,1,4e18){
		if(i*i>n) break;
		if(n%i==0){
			vec1.pb(i);
			if(i*i!=n) vec2.pb(n/i);
		}
	}
	rep(sz(vec1)) solve(vec1[i]);
	rep(sz(vec2)) solve(vec2[sz(vec2)-1-i]);
	while(q--){
		cin >> a >> b;
		y=__gcd(a,b);
		a/=y,b/=y;
		print1(ans[a]*ans[b]%MOD);
	}
	return 0;
}