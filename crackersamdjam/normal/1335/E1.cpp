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
const int MM = 2e5+5, MN = 202;

int t, n, a[MM], psa[202][MM];

int main(){
    scan(t);
    while(t--){
        scan(n);
        vector<int> v[202];
        
        for(int j = 1; j <= 200; j++)
            v[j].emplace_back(0);
        
        for(int i = 1; i <= n; i++){
            scan(a[i]);
            for(int j = 1; j <= 200; j++){
                psa[j][i] = psa[j][i-1];
            }
            psa[a[i]][i]++;
            v[a[i]].emplace_back(i);
        }
    
        for(int j = 1; j <= 200; j++){
            v[j].emplace_back(n+1);
            psa[j][n+1] = psa[j][n];
        }
        
        int ans = 0;
        
        for(int f = 1; f <= 200; f++){
            for(int s = 1; s <= 200; s++){
                if(f == s)
                    continue;
                
                for(int k = 0; k < v[f].size()/2; k++){
                    int l = v[f][k], r = v[f][v[f].size()-1-k];
                    int cnt = k*2 + psa[s][r] - psa[s][l];
                    ans = max(ans, cnt);
                }
            }
        }
        
        print(ans);
    }
    
    
    return 0;
}