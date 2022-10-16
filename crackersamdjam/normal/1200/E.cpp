#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e6+1, base = 131, mod = 1685518853;

int n;
string s, t;
ll p[MM];

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    
    p[0] = 1;
    for(int i = 1; i < MM; i++)
        p[i] = p[i-1]*base % mod;
    
    for(int z = 1; z < n; z++){
        cin >> t;
        
        ll lv = 0, rv = 0, ans = -1;
        
        for(int i = 0; i < min(s.size(), t.size()); i++){
            lv = (s[s.size()-1-i]*p[i] % mod + lv) % mod;
            rv = (rv*base % mod + t[i]) % mod;
            
            if(lv == rv)
                ans = i;
        }
        s += t.substr(ans+1);
    }
    
    cout << s << '\n';
    
    return 0;
}