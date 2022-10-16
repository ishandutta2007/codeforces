#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+1;

int n, lo[MM], hi[MM], nn;
ll ans, cnt;
vector<int> v;
bool skip[MM];

int main(){
    
    memset(lo, 0x3f, sizeof lo);
    
    scan(n);
    nn = n;
    for(int i = 0,k,a; i < n; i++){
        scan(k);
        bool b = 0;
        while(k--){
            scan(a);
            if(a > lo[i])
                b = 1;
            lo[i] = min(lo[i], a);
            hi[i] = max(hi[i], a);
        }
        if(b){
            //printf("skip %d %d\n", i, 2*nn-1);
            ans += 2*nn-1;
            nn--;
            skip[i] = 1;
        }
        else
            v.emplace_back(lo[i]);
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(skip[i])
            continue;
        //print(v[i], lower_bound(v.begin(), v.end(), hi[i])-v.begin());
        ans += lower_bound(v.begin(), v.end(), hi[i])-v.begin();
    }
    
    print(ans);
    
    return 0;
}