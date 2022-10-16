#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+2;

int n, last[MM], day = 1, cnt, pre = 0;
//last day person i was in
bool in[MM];
vector<int> ans;

int main(){
    
    scanf("%d", &n);
    for(int i = 1,a; i <= n; i++){
        scanf("%d", &a);
        //print(i, a, day);
        if(a > 0){
            if(in[a] || last[a] == day) return 0*puts("-1");
            in[a] = 1;
            last[a] = day;
            cnt++;
        }
        else{
            a = -a;
            if(!in[a] || last[a] != day) return 0*puts("-1");
            in[a] = 0;
            cnt--;
        }
        if(cnt == 0){
            day++;
            ans.push_back(i-pre);
            pre = i;
        }
    }
    
    if(cnt) return 0*puts("-1");
    
    print(ans.size());
    for(int i: ans)
        printf("%d ", i);
    
    return 0;
}