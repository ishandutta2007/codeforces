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
const int MM = 105;

struct st{
    int st, ed, c, id;
} a[MM];
int n, m, out[MM];
set<int> nx;

int main(){
    scan(n, m);
    for(int i = 1; i <= n; i++){
        nx.insert(i);
    }
    for(int i = 1; i <= m; i++){
        scan(a[i].st, a[i].ed, a[i].c);
        a[i].id = i;
        
        if(!nx.count(a[i].ed))
            return print(-1), 0;
        nx.erase(a[i].ed);
        out[a[i].ed] = m+1;
    }
    sort(a+1, a+1+m, [](st x, st y){
        return x.ed < y.ed;
    });
    for(int i = 1; i <= m; i++){
        while(a[i].c--){
            if(nx.empty())
                return print(-1), 0;
            
            int rm = *nx.lower_bound(a[i].st);
            if(rm >= a[i].ed)
                return print(-1), 0;
            
            nx.erase(rm);
            out[rm] = a[i].id;
        }
    }
    
    for(int i = 1; i <= n; i++)
        printf("%d ", out[i]);
    
    return 0;
}