#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const ll b1 = 31, b2 = 131, m1 = 1e9+9, m2 = 1494318097;
const int MM = 3e5+5;

int q, n, a, ptr;
ll h1[MM], h2[MM], ans;
map<pair<ll, ll>, ll> cnt;
stack<int> st;

int main(){
    
    scan(q);
    
    while(q--){
        
        while(!st.empty())
            st.pop();
        cnt.clear();
        cnt[{0, 0}] = 1;
        ptr = 1;
        ans = 0;
        
        scan(n);
        
        while(n--){
            scan(a);
            if(!st.empty() && a == st.top()){
                st.pop();
                ptr--;
            }
            else{
                st.push(a);
                ptr++;
                h1[ptr] = (h1[ptr-1]*b1 + a)%m1;
                h2[ptr] = (h2[ptr-1]*b2 + a)%m2;
            }
            ans += cnt[{h1[ptr], h2[ptr]}]++;
        }
        
        print(ans);
    }
    
    return 0;
}