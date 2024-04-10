#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename second, typename ... Ints> void scan(second &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename second, typename ... Ints> void print(second arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

int t, n, a[MM];

int main(){
    scan(t);
    while(t--){
        scan(n);
        set<pair<int, int>> st;
        st.insert({-n, 1});
        int nx = 1;
        while(st.size()){
            auto rm = *st.begin(); st.erase(st.begin());
            if(!rm.first) continue;
            rm.first *= -1;
            
            int mid = (rm.second + rm.second+rm.first-1)/2;
            a[mid] = nx++;
            
            st.insert({-(mid-rm.second), rm.second});
            st.insert({-(rm.second+rm.first-1-mid), mid+1});
        }
        
        for(int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        pc(10);
    }
    
    
    return 0;
}