#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

int t, n, a[MM], b[MM], psa[MM];
char s[MM];
set<int> st;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %s", &n, s+1);
        st.clear();
        for(int i = 1; i <= n; i++){
            st.insert(i);
            a[i] = 0;
        }
        int pre = 0;
        for(int i = 1; i <= n; i++){
            if(s[i-1] != '>' and (s[i] == '>' or i == n)){
                //go backwards
                for(int j = i; j > pre; j--){
                    a[j] = *--st.end();
                    st.erase(--st.end());
                }
                pre = i;
            }
            else if(a[i-1] and s[i] == '>'){
                a[i] = *--st.end();
                st.erase(--st.end());
                pre = i;
            }
        }
        for(int i = n; i > pre; i--){
            a[i] = *--st.end();
            st.erase(--st.end());
        }
        assert(st.empty());
        for(int i = 1; i <= n; i++){
            st.insert(i);
            b[i] = 0;
        }
        pre = 0;
        for(int i = 1; i <= n; i++){
            if(s[i-1] != '<' and (s[i] == '<' or i == n)){
                for(int j = i; j > pre; j--){
                    b[j] = *st.begin();
                    st.erase(st.begin());
                }
                pre = i;
            }
            else if(b[i-1] and s[i] == '<'){
                b[i] = *st.begin();
                st.erase(st.begin());
                pre = i;
            }
        }
        for(int i = n; i > pre; i--){
            b[i] = *st.begin();
            st.erase(st.begin());
        }
    
        for(int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        pc(10);
        for(int i = 1; i <= n; i++)
            printf("%d ", b[i]);
        pc(10);
    }
    
    return 0;
}
/*
1
5 <><><
 */