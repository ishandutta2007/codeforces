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
const int MM = 3e6+5;

#define lc (i<<1)
#define rc (i<<1|1)

int t, h, g, a[MM], sz[MM], n, m, ff[MM];

bool check(int i){
    int lvl = log2(i);
    if(lvl >= g) return 1;
    int tar = (1<<(g-lvl))-1;
    int half = tar/2;
    
    if(sz[i] <= tar){
        //print(i, 0);
        return 0;
    }
    
    if(a[lc] > a[rc]){
        int v = sz[lc] > half and check(lc);
        //print(i, v);
        return v;
    }
    else{
        int v = sz[rc] > half and check(rc);
        //print(i, v);
        return v;
    }
}

void rm(int i){
    assert(sz[i]);
    if(sz[i] == 1){
        sz[i] = 0;
        a[i] = 0;
        return;
    }
    if(!sz[rc] || a[lc] > a[rc]){
        a[i] = a[lc];
        sz[i]--;
        rm(lc);
    }
    else{
        a[i] = a[rc];
        sz[i]--;
        rm(rc);
    }
    sz[i] = sz[lc]+sz[rc]+1;
}

int main(){
    scan(t);
    while(t--){
        vector<int> v;
        scan(h, g);
        n = (1<<h)-1, m = (1<<g)-1;
        for(int i = 1; i <= n; i++){
            scan(a[i]);
            sz[lc] = sz[rc] = 0;
        }
        for(int i = n; i; i--){
            sz[i] = 1+sz[lc]+sz[rc];
        }
        
        for(int i = 1; i <= m; i++){
            while(check(i)){
                v.emplace_back(i);
                rm(i);
                //printf("rm %d\n", i);
            }
        }
        ll sum = 0;
        for(int i = 1; i <= m; i++){
//            printf("%d ", a[i]);
            sum += a[i];
        }
//        pc(10);
        print(sum);
        for(int i: v)
            printf("%d ", i);
        pc(10);
//        print(v.size());
//        for(int i = m; i; i--)
//            sz[i] = sz[lc] + sz[rc] + 1;
//        assert(sz[1] == m);
//        for(int i = 1; i <= m; i++)
//            printf("%d ", sz[i]);
    }
    
    return 0;
}
/*
1
4 3
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1


1
4 3
15 14 7 13 10 6 5 12 11 9 8 4 3 2 1
 */