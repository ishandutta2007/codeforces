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
using ld = long double;
const int MM = 2e5+5;

int n;
ll a[MM], psa[MM];

struct st{
    ld val;
    int mid, len;
    bool operator<(const st &o) const{
        return val < o.val;
    }
};
st ans = {0, 1, 0};

ll sum(int l, int r){
    return psa[r] - psa[l-1];
}

ld val(int i, int r){
    ld v = sum(i-r, i-1) + sum(n-r+1, n) + a[i];
    v /= (r+r+1);
    return v-a[i];
}

int main(){
    scan(n);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    sort(a+1, a+n+1);
    
    for(int i = 1; i <= n; i++)
        psa[i] = psa[i-1] + a[i];
    
    for(int i = 2; i < n; i++){
        int l = 1, m, r = min(i-1, n-i);
        while(l <= r){
            m = (l+r)/2;
            if(val(i, m) > val(i, m-1))
                l = m+1;
            else
                r = m-1;
        }
        ans = max(ans, {val(i, r), i, r});
    }
    
    int len = ans.len*2+1;
    print(len);
    for(int i = ans.mid-ans.len; i <= ans.mid; i++)
        printf("%lld ", a[i]);
    for(int i = n-ans.len+1; i <= n; i++)
        printf("%lld ", a[i]);
    
    return 0;
}
/*
4
1 2 2 12
3
2 2 12

3
2 3 12

8
1 2 3 4 5 6 7 8

4
12 3 2 1

 
 
 */