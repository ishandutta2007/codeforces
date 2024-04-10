#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 3e5+10;

int q, n, a[MM], bit[MM];
vector<int> vec[MM];
map<int, int> mp;

void update(int i, int v){
    for(i = n-i+2; i <= n+3; i += i&-i)
        bit[i] += v;
}

int query(int i){
    int ret = 0;
    for(i = n-i+2; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

int main(){
    
    scan(q);
    
    while(q--){
        
        scan(n);
        mp.clear();
        
        for(int i = 0; i <= n+5; i++){
            bit[i] = 0;
        }
        
        for(int i = 1; i <= n; i++){
            scan(a[i]);
            mp[a[i]] = 0;
            vec[i].clear();
        }
        
        int x = 0;
        for(auto &i: mp){
            i.second = ++x;
        }
        //x is how many distinct elements
        
        for(int i = 1; i <= n; i++){
            a[i] = mp[a[i]];
            vec[a[i]].push_back(i);
            //first element is always at front
        }
        
        int l = 1, r = 1, ans = 1;
        /*
        for(int i: vec[1]){
            update(i, 1);
        }*/
        
        while(r <= x){
            //check for inversions
            //print(l, r, query(vec[r].front()));
            if(query(vec[r].front())){
                for(int i: vec[l])
                    update(i, -1);
                l++; //remove l
            }
            else{
                ans = max(ans, r-l+1);
                //add last one, because now is part of "smaller" group
                for(int i: vec[r])
                    update(i, 1);
                r++;
            }
        }
        print(x - ans);
    }
    
    return 0;
}