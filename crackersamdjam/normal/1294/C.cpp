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
int main(){
    scan(t);
    while(t--){
        scan(n);
        vector<int> v;
        int inn = n;
        for(long long i = 2; i*i <= inn; i++){
            if(n % i == 0){
                n /= i;
                v.push_back(i);
                if(v.size() == 2)
                    break;
            }
        }
        if(v.size() == 2){
            long long r = inn/v[0]/v[1];
            if(r > v[1] and r*v[0]*v[1] == inn){
                puts("YES");
                print(v[0], v[1], r);
                continue;
            }
        }
        
        puts("NO");
    }
    
    return 0;
}