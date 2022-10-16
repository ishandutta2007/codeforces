#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){std::cout<<n;}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 3e5+5;

char a[MM], b[MM], c[MM];
int n, l, r, t, al, ar, bl, br, rem;

int main(){
    scanf("%s %s", a, b);
    n = strlen(a);
    sort(a, a+n);
    sort(b, b+n);
    l = al = bl = 0, r = ar = br = n-1;
    int fs = (n+1)/2, ss = n-fs;
    ar = fs-1;
    bl = n-ss;
    
//    print(ar, bl);
//    printf("%s\n%s\n", a, b);
    
    while(l <= r){
        if(!t){
//            print(t, a[al], b[br]);
            if(a[al] < b[br]){
                c[l++] = a[al++];
            }
            else{
                c[r--] = a[ar--];
            }
        }
        else{
//            print(t, b[br], a[al]);
            if(b[br] > a[al]){
                c[l++] = b[br--];
            }
            else{
                c[r--] = b[bl++];
            }
        }
        t^=1;
    }
    printf("%s\n", c);
    
    return 0;
}
/*
acddd
bbbbc
 */