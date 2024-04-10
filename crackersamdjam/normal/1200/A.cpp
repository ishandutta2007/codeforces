#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, a[10];
string str;

int main(){
    
    cin >> n;
    
    cin >> str;
    
    for(int i = 0; i < n; i++){
        if(str[i] == 'L'){
            for(int j = 0; j <= 9; j++){
                if(!a[j]){
                    a[j] = 1;
                    break;
                }
            }
        }
        else if(str[i] == 'R'){
            for(int j = 9; j >= 0; j--){
                if(!a[j]){
                    a[j] = 1;
                    break;
                }
            }
        }
        else{
            a[str[i]-'0'] = 0;
        }
    }
    
    for(int i = 0; i <= 9; i++)
        pc(a[i]+'0');
    pc(10);
    
    return 0;
}