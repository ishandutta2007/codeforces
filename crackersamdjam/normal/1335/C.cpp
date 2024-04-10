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
const int MM = 2e5+5;

int t, n;
map<int, int> cnt;

bool go(int k){
    int id = 0, val = 0;
    for(auto &i: cnt){
        if(i.second > k){
            i.second -= k;
            val = k;
            id = i.first;
            break;
        }
    }
    if(!id){
        for(auto &i: cnt){
            if(i.second >= k){
                i.second -= k;
                val = k;
                id = i.first;
                break;
            }
        }
    }
    
    int a = 0;
    for(auto i: cnt){
        if(i.second > 0){
            a++;
        }
    }
    
    cnt[id] += val;
    
    if(id and a >= k){
        return 1;
    }
    return 0;
}

int main(){
    scan(t);
    while(t--){
        cnt.clear();
        scan(n);
        for(int i = 0,a; i < n; i++){
            scan(a);
            cnt[a]++;
        }
        int l = 0, m, r = n;
        while(l <= r){
            m = (l+r)/2;
            if(go(m))
                l = m+1;
            else
                r = m-1;
        }
        print(r);
    }
    
    
    return 0;
}