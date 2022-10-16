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
typedef long long ll;
const int MM = 1005, MN = 1e5+5;

int n, m, t, a[MM][MM], ans[MM], mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
int dis[MM][MM], cnt;
queue<pair<int, int>> q;

bool go(int i, int j){
    for(int k = 0; k < 4; k++){
        int ni = i+mx[k], nj = j+my[k];
        if(ni and nj and ni <= n and nj <= m and a[ni][nj] == a[i][j])
            return 1;
    }
    return 0;
}

int main(){
    memset(dis, 0x3f, sizeof dis);
    scan(n, m, t);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = gc-'0';
        }
        gc;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(go(i, j)){
                dis[i][j] = 0;
                q.emplace(i, j);
                cnt++;
            }

    while(q.size()){
        int i =  q.front().first, j = q.front().second; q.pop();
        for(int k = 0; k < 4; k++){
            int ni = i+mx[k], nj = j+my[k];
            if(ni and nj and ni <= n and nj <= m and dis[i][j] + 1 < dis[ni][nj]){
                dis[ni][nj] = dis[i][j] + 1;
                q.emplace(ni, nj);
            }
        }
    }

    for(int k = 0; k < t; k++){
        int i, j; ll p;
        scan(i, j, p);
        if(p < dis[i][j] || !cnt){
            print(a[i][j]);
        }
        else{
            p -= dis[i][j];
            p %= 2;
            print(a[i][j]^p);
        }
    }

    
    return 0;
}