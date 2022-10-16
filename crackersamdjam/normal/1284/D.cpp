#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using T = int;
const int MM = 2e5+9;

int n, bit[2][MM], sa[MM], ea[MM], sb[MM], eb[MM];
map<int, int> mpa, mpb;

void up(int id, int i, int v){
    for(i++; i < MM; i += i&-i)
        bit[id][i] += v;
}

int qu(int id, int i){
    int r = 0;
    for(i++; i; i -= i&-i)
        r += bit[id][i];
    return r;
}

struct st{
    int x, v, l, r;
    //v1 add, v2 remove
    st(int _x, int _v, int _l, int _r): x(_x), v(_v), l(_l), r(_r) {}
    bool operator<(const st &o) const{
        if(x == o.x)
            return v < o.v;
        return x < o.x;
    }
};
vector<st> v, v2;

int main(){
    
    scan(n);
    for(int i = 0; i < n; i++){
        scan(sa[i], ea[i], sb[i], eb[i]);
        mpa[sa[i]] = mpa[ea[i]] = 0;
        mpb[sb[i]] = mpb[eb[i]] = 0;
    }
    
    int t = 1;
    for(auto &i: mpa)
        i.second = ++t;
    t = 1;
    for(auto &i: mpb)
        i.second = ++t;
    
    for(int i = 0; i < n; i++){
        sa[i] = mpa[sa[i]], ea[i] = mpa[ea[i]];
        sb[i] = mpb[sb[i]], eb[i] = mpb[eb[i]];
        v.emplace_back(sa[i], 1, sb[i], eb[i]);
        v.emplace_back(ea[i], 2, sb[i], eb[i]);
        
        v2.emplace_back(sb[i], 1, sa[i], ea[i]);
        v2.emplace_back(eb[i], 2, sa[i], ea[i]);
    }
    
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    
    int in = 0;
    for(auto i: v){
        //print(i.x, i.v, i.l, i.r);
        if(i.v == 1){
            int cnt = in - qu(1, i.l-1) - (in - qu(0, i.r));
            //print(-qu(1, i.l-1), -(in-qu(0, i.r)), cnt);
            if(cnt != in){
                puts("NO");
                return 0;
            }
            up(0, i.l, 1);
            up(1, i.r, 1);
            in++;
        }
        else{
            up(0, i.l, -1);
            up(1, i.r, -1);
            in--;
        }
    }
    
    in = 0;
    memset(bit, 0, sizeof bit);
    v = v2;
    
    for(auto i: v){
        if(i.v == 1){
            int cnt = in - qu(1, i.l-1) - (in - qu(0, i.r));
            if(cnt != in){
                puts("NO");
                return 0;
            }
            up(0, i.l, 1);
            up(1, i.r, 1);
            in++;
        }
        else{
            up(0, i.l, -1);
            up(1, i.r, -1);
            in--;
        }
    }
    
    puts("YES");
    
    return 0;
}
/*
2
1 2 1 2
3 4 1 2
 */