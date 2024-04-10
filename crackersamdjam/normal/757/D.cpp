#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
#define ll long long
const ll mod = 1e9+7;
const int MM = (1<<21);

map<int, ll> dp[77];

int calc(string s){
    int v = 0;
    for(char c: s){
        v <<= 1;
        v += c-'0';
        if(v > 22)
            return -1;
    }
    // cout<<s<<" = "<<v<<endl;
    return v;
}

int n, req[MM], ss[22];
string s;
ll ans;

int main(){

    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>s;
    s = "0"+s;
    dp[0][0] = 1;
    for(int i = 1; i < 21; i++)
        ss[i] = 1+__lg(i);
    for(int i = 1; i < MM; i++){
        for(int j = 0; j < 21; j++){
            if(i&(1<<j)){
                req[i] += ss[j];
            }
        }
    }

    for(int i = 1; i <= n ;i++){
        dp[i][0] = 1;
        for(int j = 0; j < i; j++){
            int v = calc(s.substr(j+1, i-j));
            // print(j, i, v);
            if(v < 21 and v > 0){
                //v--;

                for(auto &k: dp[j]){
                    int nx = k.first|(1<<v);

                    if(k.first){
                        int hi = __lg(nx)+1;
                        int rem = ((1<<hi)-1)^nx;
                        if(rem > 1)
                        if(hi>1 and n-i < req[rem]){
                            // print(j, i, k.first, nx, v, hi, rem, req[rem]);
                            continue;
                        }
                    }

                    dp[i][nx] += k.second;
                    if(dp[i][nx] >= mod)
                        dp[i][nx] -= mod;
                }

            }
        }

        int mask = 0;
        for(int j = 1; j < 21; j++){
            mask |= (1<<j);
            ans += dp[i][mask];
            if(ans >= mod)
                ans -= mod;
        }
    }

    cout<<ans;
    
    return 0;
}

// 20 74
// 21 79
/*
75
000001001101010101000101100010110010000110011110011010001011110101100001010

582834320
*/