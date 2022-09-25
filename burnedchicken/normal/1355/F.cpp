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
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=1005;
//i_am_noob
int t,x=1,lim=1e9,inf=1e18,cnt=0,k,y,q,ans;
vector<int> vec[30],prime,vec1,vec2;
bool isprime[maxn],flag;

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

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    find_prime();
    for(auto i: prime){
        if((__int128)x*i>inf){
            x=1;
            cnt++;
        }
        x*=i;
        vec[cnt].pb(i);
    }
    cin >> t;
    while(t--){
        vec1.clear(),vec2.clear();
        flag=false;
        y=1,q=0;
        rep(cnt){
            x=1;
            for(auto j: vec[i]) x*=j;
            q++;
            print2("?",x);
            cout << flush;
            cin >> k;
            for(auto j: vec[i]) if(k%j==0) {vec1.pb(j);y*=j;}
            if(i==2&&vec1.empty()){
                print2("!",8);
                cout << flush;
                flag=true;
                break;
            }
            if(y*vec[i+1][0]*vec[i+1][0]*vec[i+1][0]>lim) break;
        }
        if(flag) continue;
        rep((sz(vec1)+1)/2){
            x=1;
            while(1){
                if(x*vec1[2*i]>lim) break;
                x*=vec1[2*i];
            }
            y=1;
            if(2*i+1<sz(vec1)) while(1){
                if(y*vec1[2*i+1]>lim) break;
                y*=vec1[2*i+1];
            }
            print2("?",x*y);
            cout << flush;
            cin >> k;
            vec2.pb(0);
            while(k%vec1[2*i]==0){
                vec2.back()++;
                k/=vec1[2*i];
            }
            if(2*i+1<sz(vec1)){
                vec2.pb(0);
                while(k%vec1[2*i+1]==0){
                    vec2.back()++;
                    k/=vec1[2*i+1];
                }
            }
        }
        ans=1;
        for(auto i: vec2) ans*=i+1;
        print2("!",ans*2);
        cout << flush;
    }
    return 0;
}