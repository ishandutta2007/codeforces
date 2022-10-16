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
using pii = pair<int, int>;
const int MM = 2e5+5;

int t, n, a[MM];


int main(){
    scan(t);
    while(t--){
        scan(n);
        assert(n < MM);
        vector<pii> v;
        vector<int> ans;
        scan(a[0]);
        v.emplace_back(a[0], 1);
        for(int i = 1; i < n; i++){
            scan(a[i]);
            if(v.back().first == a[i])
                v.back().second++;
            else
                v.emplace_back(a[i], 1);
        }
        
        int back = 0;
        if(v.size() > 1 and v.back().first == v.front().first){
            v.front().second += v.back().second;
            back = v.back().second;
            v.pop_back();
        }
        
        int mx = 0;
        for(auto i: v)
            mx = max(mx, i.second);
        
        if(v.size() == 1){
            print(1);
            while(v[0].second--)
                ans.emplace_back(1);
        }
        else if(v.size()%2 == 1 and mx == 1){
            print(3);
            auto rm = v.back();
            v.pop_back();
            int c = 0;
            for(auto i: v){
                while(i.second--)
                    ans.emplace_back(c+1);
                c = !c;
            }
            while(rm.second--)
                ans.emplace_back(3);
                
        }
        else{
            if(v.size() % 2 == 0){
                mx = 0;
                //no extra needed
            }
            print(2);
            int c = 0;
            for(auto i: v){
                if(i.second > 1 and mx){
                    mx = -1;
                    i.second--;
                }
                while(i.second--)
                    ans.emplace_back(c+1);
                c = !c;
                
                if(mx == -1){
                    mx = 0;
                    ans.emplace_back(c+1);
                    c = !c;
                }
            }
        }
        for(int i = back; i < ans.size(); i++)
            printf("%d ", ans[i]);
        for(int i = 0; i < back; i++)
            printf("%d ", ans[i]);
        pc(10);
    }
    
    return 0;
}
/*
5
4
1 2 3 1
7
1 1 1 2 3 3 3
4
1 1 2 2
5
1 2 2 3 4
4
1 2 2 3

 */