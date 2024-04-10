#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, m, k, add;
vector<pair<int, char>> v;

int main(){
    
    scan(n, m, k);
    
    for(int i = 0; i < n-1; i++){
        add = min(k, m-1);
        v.emplace_back(add, 'R');
        k -= add;
        add = min(k, m-1);
        v.emplace_back(add, 'L');
        k -= add;
        if(k){
            k--;
            v.emplace_back(1, 'D');
        }
    }
    if(!k) goto done;
    
    for(int i = 1; i < m; i++){
        if(k){
            k--;
            v.emplace_back(1, 'R');
        }
        add = min(k, n-1);
        v.emplace_back(add, 'U');
        k -= add;
        add = min(k, n-1);
        v.emplace_back(add, 'D');
        k -= add;
    }
    if(!k) goto done;
    add = min(k, m-1);
    v.emplace_back(add, 'L');
    k -= add;
    
    add = min(k, n-1);
    v.emplace_back(add, 'U');
    k -= add;
    
    done:;
    
    if(k)
        return puts("NO"), 0;
    
    int cnt = 0;
    for(auto i: v)
        cnt += (i.first>0);
    
    puts("YES");
    print(cnt);
    for(auto i: v){
        if(!i.first)
            continue;
        printn(i.first), pc(32), pc(i.second), pc(10);
    }
    
    return 0;
}