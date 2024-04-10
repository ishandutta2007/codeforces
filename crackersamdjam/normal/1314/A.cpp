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
const int MM = 4e5+5;

int n;
ll ans;
pair<int, int> a[MM];
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbst;
bbst t;

int main(){
    scan(n);
    for(int i = 0; i < n; i++)
        scan(a[i].second);
    for(int i = 0; i < n; i++)
        scan(a[i].first);
    sort(a, a+n);
    for(int i = n-1; i >= 0; i--){
        int id = a[i].second;
        ll l = id, m, r = 2e9+2;
        if(t.lower_bound(id) == t.end() or (*t.lower_bound(id) != id)){
            r = 0;
        }
        while(l <= r){
            m = (l+r)/2;
            if(t.lower_bound(m) != t.end() and *t.lower_bound(m) == m and (int)t.order_of_key(m)-(int)t.order_of_key(id) == m-id)
                l = m+1;
            else
                r = m-1;
        }
        ans += (ll)(l-id)*a[i].first;
        t.insert(l);
        //print(id, l);
    }
    print(ans);
    
    return 0;
}