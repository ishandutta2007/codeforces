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
const int MM = 2e5+5;

int n, k, a[MM];
map<int, int> cnt;
ll psa[MM];

int main(){
    scan(n, k);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        if(++cnt[a[i]] == k){
            return puts("0"), 0;
        }
    }
    
    sort(a+1, a+n+1);
    ll v = a[k];
    ll sum = 0;
    for(int i = 1; i < k; i++){
        sum += max(0LL, v-1-a[i]); //get all to v-1
    }
    sum += k-cnt[v]; //add all 1 except those already right
    ll ans = sum;
    
    
    reverse(a+1, a+1+n);
    v = a[k];
    sum = 0;
    for(int i = 1; i < k; i++){
        sum += max(0LL, a[i]-(v+1));
    }
    sum += k-cnt[v];
    ans = min(ans, sum);
    
    reverse(a+1, a+1+n);
    for(int i = 1; i <= n; i++)
        psa[i] = psa[i-1] + a[i];
    for(int i = 1; i <= n; i++){
        v = a[i];
        sum = i*v - psa[i] + ((psa[n] - psa[i]) - (n-i)*v);
//        print(i, v, i*v, - psa[i], psa[n]-psa[i], -(n-i)*v);
        sum -= n-k;
//        print(sum);
        ans = min(ans, sum);
    }
    
    print(ans);
    
    return 0;
}