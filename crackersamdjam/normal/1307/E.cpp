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
const int MM = 5005;

ll mod = 1e9+7;
ll bestdp, totcnt;
int n, m, a[MM];
vector<int> cnt[MM];
vector<int> cow[MM];

int main(){
    scan(n, m);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        cnt[a[i]].emplace_back(i);
    }
    for(int i = 0,t,h; i < m; i++){
        scan(t, h);
        cow[t].emplace_back(h);
    }
    for(int i = 1; i <= n; i++)
        sort(cow[i].begin(), cow[i].end());
    //[1, mid], (mid, n]
    for(int mid = 0; mid <= n; mid++){
        
        int tt = upper_bound(cnt[a[mid]].begin(), cnt[a[mid]].end(), mid)-cnt[a[mid]].begin();
        if(mid != 0 and !binary_search(cow[a[mid]].begin(), cow[a[mid]].end(), tt))
            continue;
        //now one of them is forced to be left endpt
        
        ll dp = 0, dpcnt = 1;
        for(int i = 1; i <= n; i++){
            int l = upper_bound(cnt[i].begin(), cnt[i].end(), mid)-cnt[i].begin();
            int r = cnt[i].size()-l;
            int one = 0, two = 0;
            
            if(i == a[mid]){
                //forced left side
                for(int j: cow[i]){
                    //print(-1, j, tt, r);
                    if(j != tt and j <= r)
                        one++;
                }
                if(one){
                    dp += 2;
                    dpcnt = dpcnt*one%mod;
                }
                else{
                    dp++;
                }
            }
            else{
                for(int j: cow[i]){
                    int op = (j <= l) + (j <= r);
                    if(op == 2)
                        two++;
                    if(op == 1)
                        one++;
                }
                if(two and two+one >= 2){
                    dp += 2;
                    dpcnt = dpcnt*(two*one%mod + two*(two-1)%mod) % mod;
                }
                else if(two){ //only one two
                    dp++;
                    dpcnt = dpcnt*2%mod;
                }
                else if(one){
                    dp++;
                    dpcnt = dpcnt*one%mod;
                }
            }
        }
        //print(mid, dp, dpcnt);
        if(dp > bestdp){
            bestdp = dp;
            totcnt = dpcnt;
        }
        else if(dp == bestdp){
            totcnt += dpcnt;
            totcnt %= mod;
        }
    }
    print(bestdp, totcnt);
    
    return 0;
}
/*
3 1
1 3 2
2 1

 */