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
const int MM = 1e5+5;

int t, n;
vector<int> v[MM];
bool useda[MM], usedb[MM];

int main(){
    scan(t);
    while(t--){
        scan(n);
        for(int i = 1; i <= n; i++){
            v[i].clear();
            useda[i] = usedb[i] = 0;
        }
        for(int i = 1,k,a; i <= n; i++){
            scan(k);
            while(k--){
                scan(a);
                v[i].emplace_back(a);
            }
            sort(all(v[i]));
            for(int j: v[i]){
                if(!usedb[j]){
                    usedb[j] = useda[i] = 1;
                    break;
                }
            }
        }
        int nx = 1;
        while(nx <= n and usedb[nx])
            nx++;
        for(int i = 1; i <= n; i++){
            if(useda[i] or nx > n)
                continue;
            puts("IMPROVE");
            printf("%d %d\n", i, nx);
            goto out;
        }
        puts("OPTIMAL");
        out:;
    }
    
    
    return 0;
}