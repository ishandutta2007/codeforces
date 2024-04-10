//
// Created by calabash_boy on 18-10-18.
//
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif

#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;


/************* header ******************/
const int maxn = 1e5+100;
int a[maxn],b[maxn];
int t[maxn];
int pre[maxn*4];
vector<int> E[maxn*4];
inline int id(int pos,int num){
    return pos *4 + num;
}
inline pair<int,int> dec(int id){
    return {id/4,id%4};
}
inline bool valid(int pos,int ti,int ti1){
    return (ti|ti1) == a[pos] && (ti & ti1) == b[pos];
}
void bfs(int s){
    memset(pre,-1,sizeof pre);
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){
        int head = Q.front();Q.pop();
        for (int v : E[head]){
            if (pre[v] == -1){
                pre[v] = head;
                Q.push(v);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    rep(i,1,n){
        rep(a,0,4)rep(b,0,4){
            if (valid(i,a,b)){
                E[id(i,a)].push_back(id(i+1,b));
            }
        }
    }
    rep(a,0,4){
        E[id(0,0)].push_back(id(1,a));
    }
    bfs(id(0,0));
    rep(a,0,4){
        if (pre[id(n,a)] == -1)continue;
        int now = id(n,a);
        vector<int>ans(0);
        while (now){
            ans.push_back(dec(now).second);
            now = pre[now];
        }
        reverse(ans.begin(),ans.end());
        puts("YES");
        for (int x:ans){
            printf("%d ",x);
        }
        exit(0);
    }
    leave(NO);
    return 0;
}