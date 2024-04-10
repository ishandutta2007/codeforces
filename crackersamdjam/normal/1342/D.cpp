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

int n, k, a[MM], b[MM], cnt[MM];
vector<vector<int>> v;
set<pair<int, int>> st;

int main(){
    scan(n, k);
    for(int i = 0; i < n; i++){
        scan(a[i]);
        cnt[a[i]]++;
    }
    for(int i = 1; i <= k; i++)
        scan(b[i]);
    
    v.emplace_back();
    st.emplace(0, 0);
    
    for(int i = k; i > 0; i--){
        while(cnt[i]--){
            int id = st.begin()->second, x = st.begin()->first;
            if(x < b[i]){
                v[id].push_back(i);
                st.erase(st.begin());
                st.insert({x+1, id});
            }
            else{
                v.emplace_back();
                v.back().push_back(i);
                st.insert({1, v.size()-1});
            }
        }
    }
    
    print(v.size());
    for(auto i: v){
        printf("%ld ", i.size());
        for(int j: i)
            printf("%d ", j);
        pc(10);
    }
    
    return 0;
}