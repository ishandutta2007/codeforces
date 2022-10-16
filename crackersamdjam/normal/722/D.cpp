#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 5e4+2;

int n, a[MM];
set<int, greater<int>> st;
set<int> ans;

int main(){

    //manually remove
    /*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    */
    scan(n);
    for(int i = 0; i < n; i++){
        scan(a[i]);
        st.insert(a[i]);
    }
    int cur = *st.begin();
    while(1){
        //printf("cur %d\n", cur);
        int v = cur/2;
        while(v > 0){
            if(!st.count(v)){
                st.erase(st.lower_bound(cur));
                st.insert(v);
                //printf("rep %d w %d\n", cur, v);
                break;
            }
            v /= 2;
        }
        //nx:
        if(st.upper_bound(cur) == st.end())
            break;
        cur = *st.upper_bound(cur);
    }
    
    for(int i: st)
        ans.insert(i);

    for(int i: ans)
        printf("%d ", i);

    return 0;
}