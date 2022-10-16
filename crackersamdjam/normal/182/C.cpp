#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

constexpr int MM = 1e5;

int n, len, k, a[MM];
long long sum, best;
std::multiset<int> sl, sr;

#define max(a, b) ((a) > (b) ? (a) : (b))

void run(){
    sl.clear();
    sr.clear();
    sum = 0;
    for(int i = 0; i < len; i++){
        sum += a[i];
        sr.insert(a[i]);
    }
    for(int i = 0; i < k; i++){
        auto ptr = sr.begin();
        int rm = *ptr;
        sr.erase(ptr);
        sum -= rm;
        sl.insert(rm);
        sum += abs(rm);
    }
    best = max(best, sum);
    for(int i = len; i < n; i++){
        int rm = a[i-len];
        auto ptr = sr.find(rm);
        if(ptr != sr.end()){
            sr.erase(ptr);
            sum -= rm;
            sr.insert(a[i]);
            sum += a[i];
        }
        else{
            sl.erase(sl.find(rm));
            sum -= abs(rm);
            sl.insert(a[i]);
            sum += abs(a[i]);
        }
        auto pl = prev(sl.end()), pr = sr.begin();
        while(*pl > *pr){
            int f = *pl, s = *pr;
            sl.erase(pl);
            sr.erase(pr);
            sum -= abs(f);
            sum -= s;
            sl.insert(s);
            sr.insert(f);
            sum += abs(s);
            sum += f;
            pl = prev(sl.end()), pr = sr.begin();
        }
        
        best = max(best, sum);
    }
}

int main(){
    scan(n, len);
    for(int i = 0; i < n; i++)
        scan(a[i]);
    scan(k);
    
    if(k >= len){
        for(int i = 0; i < n; i++){
            a[i] = abs(a[i]);
            sum += a[i];
            if(i >= len)
                sum -= a[i-len];
            best = max(best, sum);
        }
        print(best);
        return 0;
    }
    if(!k){
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(i >= len)
                sum -= a[i-len];
            if(i >= len-1)
                best = max(best, sum>0?sum:-sum);
        }
        print(best);
        return 0;
    }
    
    run();
    for(int i = 0; i < n; i++)
        a[i] = -a[i];
    run();
    
    print(best);
    exit(0);
    
    return 0;
}