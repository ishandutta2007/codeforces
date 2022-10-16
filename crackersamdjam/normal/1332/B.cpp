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
const int MM = 1002;

int t, n, a[MM], b[MM];

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(){
    scan(t);
    while(t--){
        scan(n);
        for(int i = 0; i < n; i++){
            scan(a[i]);
            for(int j = 0; j < p.size(); j++){
                if(a[i] % p[j] == 0){
                    b[i] = j;
                    break;
                }
            }
        }
        map<int, int> mp;
        int nx = 0;
        for(int i = 0; i < n; i++){
            if(!mp[b[i]])
                mp[b[i]] = ++nx;
        }
        print(nx);
        for(int i = 0; i < n; i++)
            printf("%d ", mp[b[i]]);
        pc(10);
    }
    
    return 0;
}