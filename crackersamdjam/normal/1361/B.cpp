#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2e6+100;
const ll mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int t, n, mp[MM];
ll p;
vector<int> rm;

int main(){
    scan(t);
    while(t--){
        for(int i: rm)
            mp[i] = 0;
        rm.clear();
        
        scan(n, p);
        for(int i = 0,a; i < n; i++){
            scan(a);
            
            mp[a]++;
            rm.emplace_back(a);
        }
        if(p == 1){
            print(n&1);
            continue;
        }
        ll dif = 0;
        
        sort(all(rm));
        rm.erase(unique(rm.begin(), rm.end()), rm.end());
        
        
        for(int id = (int)rm.size()-1; id >= 0; id--){
            int i = rm[id];
            mp[i] &= 1;
            if(mp[i]){
                
                dif = fpow(p, i, mod);
                mp[i] = 0;
                
                ll rem = 1;
                //rem = how many of cur one needed to cancel extrq
                
                for(int j = i-1; j >= 0 and rem < MM; j--){
                    rem *= p;
                    ll sub = min((ll)mp[j], rem);
                    
                    rem -= sub;
                    
                    dif -= sub*fpow(p, j, mod)%mod;
                    if(dif < 0)
                        dif += mod;
                    
                    mp[j] -= sub;
                    
                    if(!rem)
                        break;
                }
                
                if(rem){
                    break;
                }
                else{
                    assert(!dif);
                }
            }
        }
    
        for(int id = (int)rm.size()-1; id >= 0; id--){
            int i = rm[id];
//            print(i, mp[i]);
            dif -= fpow(p, i, mod)*mp[i]%mod;
            dif %= mod;
        }
        dif %= mod;
        if(dif < 0)
            dif += mod;
        print(dif);
    }
    
    return 0;
}