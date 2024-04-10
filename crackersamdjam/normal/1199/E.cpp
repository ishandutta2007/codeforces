#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 5e5+5;

int n, m, t;
bool used[MM];
vector<int> ind, mat;

int main(){
    scan(t);
    while(t--){
        scan(n, m);
        for(int i = 1,a,b; i <= m; i++){
            scan(a, b);
            if(!used[a] and !used[b]){
                used[a] = used[b] = 1;
                mat.push_back(i);
            }
        }
        if(mat.size() >= n){
            mat.resize(n);
            puts("Matching");
            for(int i: mat)
                printf("%d ", i);
            pc(10);
        }
        else{
            for(int i = 1; i <= 3*n; i++){
                if(!used[i]){
                    ind.push_back(i);
                }
            }
            ind.resize(n);
            puts("IndSet");
            for(int i: ind)
                printf("%d ", i);
            pc(10);
        }
        mat.clear();
        ind.clear();
        for(int i = 0; i <= 3*n; i++)
            used[i] = 0;
    }
    
    return 0;
}