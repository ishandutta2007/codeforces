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
const int MM = 100005;

int n;
ll a[MM];
map<int, vector<int>> v;

int main(){
    scan(n);
    for(int i = 0; i < n; i++){
        scan(a[i]);
        for(ll j = 2; j*j <= a[i]; j++){
            if(a[i] % j == 0){
                int cnt = 0;
                while(a[i] % j == 0){
                    a[i] /= j;
                    cnt++;
                }
                // print(i, j, cnt);
                v[j].emplace_back(cnt);
            }
        }
        if(a[i] > 1){
            v[a[i]].emplace_back(1);
            // print(i, a[i], 1);
        }
    }
    ll ans = 1;
    for(auto &i: v){
        // print(i.first, i.second.size());
        if(i.second.size() <= n-2)
            continue;
        while(i.second.size() < n)
            i.second.emplace_back(0);
        sort(all(i.second));
        int cnt = i.second[1];
        while(cnt--){
            ans *= i.first;
        }
    }
    print(ans);
    

    
    return 0;
}