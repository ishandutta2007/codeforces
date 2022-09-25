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
int n,a[maxn],x,b[maxn];
vector<int> prime,vec[maxn];
bool isprime[10000005],flag=false,flag1;
set<int> st;

void find_prime(){
    isprime[0]=isprime[1]=false;
    rep2(i,2,10000005) isprime[i]=true;
    rep2(i,2,10000005) if(isprime[i]){
        prime.pb(i);
        for(int j=i*i; j<10000005; j+=i) isprime[j]=false;
    }
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	find_prime();
	cin >> n;
	rep(n) cin >> a[i];
	rep2(i,2,maxn){
	    x=i;
	    for(auto j:prime){
	        if(j*j>x) break;
	        if(x%j==0) vec[i].pb(j);
	        while(x%j==0) x/=j;
	    }
	    if(x>1) vec[i].pb(x);
	}
    rep(n){
        if(!flag){
            for(auto j:vec[a[i]]){
                if(st.count(j)){
                    flag=true;
                    x=j;
                    break;
                }
                st.insert(j);
            }
            if(flag){
                for(auto j:vec[a[i]]){
                    if(x==j) break;
                    st.erase(j);
                }
                rep2(j,a[i]+1,maxn){
                    flag1=true;
                    for(auto k:vec[j]){
                        if(st.count(k)){
                            flag1=false;
                            break;
                        }
                    }
                    if(flag1){
                        b[i]=j;
                        for(auto k:vec[j]) st.insert(k);
                        break;
                    }
                }
                rep1(j,sz(prime)) if(!st.count(prime[j])){
                    x=j;
                    break;
                }
                continue;
            }
        }
        if(!flag){
            b[i]=a[i];
            continue;
        }
        b[i]=prime[x];
        x++;
        while(st.count(prime[x])) x++;
    }
    rep(n) print0(b[i]);
    cout << "\n";
	return 0;
}