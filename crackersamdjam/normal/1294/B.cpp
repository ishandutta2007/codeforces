#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int t, n;
pair<int, int> a[1002];

int main(){
    scan(t);
    while(t--){
        scan(n);
        bool pos = 1;
        vector<char> ans;
        for(int i = 0; i < n; i++)
            scan(a[i].first, a[i].second);
        sort(a, a+n);
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if(x > a[i].first || y > a[i].second)
                pos = 0;
            while(x < a[i].first){
                x++;
                ans.push_back('R');
            }
            while(y < a[i].second){
                y++;
                ans.push_back('U');
            }
        }
        puts(pos ? "YES" : "NO");
        if(pos){
            for(char c: ans)
                pc(c);
            pc(10);
        }
    }
    
    return 0;
}