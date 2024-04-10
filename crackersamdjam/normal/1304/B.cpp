#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, m;
deque<string> ans;
string v[101], mid;
bool used[101];

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        string op = v[i];
        reverse(op.begin(), op.end());
        for(int j = 0; j < i; j++){
            if(!used[j] and v[j] == op){
                used[j] = 1;
                used[i] = 1;
                ans.push_front(v[j]);
                ans.push_back(v[i]);
            }
        }
    }
    if(ans.size() % 2 == 0){
        for(int i = 0; i < n; i++){
            string op = v[i];
            reverse(op.begin(), op.end());
            if(!used[i] and v[i] == op){
                mid = v[i];
            }
        }
    }
    int cnt = mid.size();
    for(auto i: ans)
        cnt += i.size();
    print(cnt);
    for(int i = 0; i < ans.size()/2; i++)
        cout<<ans[i];
    cout<<mid;
    for(int i = ans.size()/2; i < ans.size(); i++)
        cout<<ans[i];
    
    return 0;
}