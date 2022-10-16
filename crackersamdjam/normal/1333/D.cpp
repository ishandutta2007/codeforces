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
const int MM = 3003;

int n, k;
char s[MM];
vector<deque<int>> v;

int main(){
    scanf("%d %d %s", &n, &k, s+1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += (s[i] == 'L');
    }
    int tot = 0;
    while(1){
        v.push_back(deque<int>());
        for(int i = 1; i < n; i++){
            if(s[i] == 'R' and s[i+1] == 'L'){
                swap(s[i], s[i+1]);
                v.back().emplace_back(i);
                tot++;
                i++; //can not do again
            }
        }
        if(v.back().empty()){
            v.pop_back();
            break;
        }
    }
    if(k > tot or k < v.size()){
        return print(-1), 0;
    }
    k -= v.size();
    for(auto i: v){
        while(i.size() > 1 and k){
            print(1, i.front());
            i.pop_front();
            k--;
        }
        printf("%ld", i.size());
        for(int j: i)
            printf(" %d", j);
        pc(10);
    }
    
    
    return 0;
}