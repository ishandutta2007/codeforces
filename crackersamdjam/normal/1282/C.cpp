#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
 
using namespace std;
using ll = long long;
const int MM = 2e5+2;
 
int m, n, tp[MM];
ll t, a, b;
vector<int> E, H;
 
int main(){
    
    scan(m);
    while(m--){
        E.clear();
        H.clear();
        scan(n, t, a, b);
        for(int i = 0; i < n; i++)
            scan(tp[i]);
        for(int i = 0,tt; i < n; i++){
            scan(tt);
            if(tp[i])
                H.push_back(tt);
            else
                E.push_back(tt);
        }
        E.push_back(t+1);
        H.push_back(t+1);
        sort(E.begin(), E.end());
        sort(H.begin(), H.end());
        int ans = 0;
        for(int i = 0; i < H.size(); i++){
            ll nx = H[i]; //solve all before this time
            ll curt = (ll)i*b;
            if(curt >= nx)
                continue;
            ll rem = nx-1-curt;
            //solve rem/a
            int l = min((ll)E.size()-1, rem/a); //-1+1 for next
            curt += (ll)a*l;
            assert(curt < nx);
            if(curt < nx and curt < E[l]){
                //print(curt, i, l);
                ans = max(ans, i+l);
            }
        }
        
        //idk
        swap(E, H);
        swap(a, b);
        for(int i = 0; i < H.size(); i++){
            ll nx = H[i]; //solve all before this time
            ll curt = (ll)i*b;
            if(curt >= nx)
                continue;
            ll rem = nx-1-curt;
            //solve rem/a
            int l = min((ll)E.size()-1, rem/a); //-1+1 for next
            curt += (ll)a*l;
            assert(curt < nx);
            if(curt < nx and curt < E[l]){
                //print(curt, i, l);
                ans = max(ans, i+l);
            }
        }
        
        
        print(ans);
    }
    
    return 0;
}