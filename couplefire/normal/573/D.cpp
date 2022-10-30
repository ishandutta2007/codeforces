#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int N = 30005;
const ll INF = 1e15;

struct node{int val, id;};

inline ll ckmax(ll& a, ll b){return a<b?a=b:a;}
bool cmp(node a, node b){return a.val>b.val;}

int n, q, p[N]; ll dp[N];
node w[N], h[N];
 
int main(){
    // freopen("a.in", "r", stdin);
    scanf("%d %d", &n, &q);
    for(int i = 1; i<=n; ++i)
        scanf("%d", &w[i].val), w[i].id = i;
    for(int i = 1; i<=n; ++i)
        scanf("%d", &h[i].val), h[i].id = i;
    iota(p+1, p+n+1, 1);
    sort(w+1, w+n+1, cmp); sort(h+1, h+n+1, cmp);
    while(q--){
        int a, b; scanf("%d %d", &a, &b); swap(p[a], p[b]);
        for(int i = 1; i<=n; ++i){dp[i] = 0;
            if(p[w[i].id]^h[i].id) ckmax(dp[i], dp[i-1]+1ll*w[i].val*h[i].val);
            if(i>1 && (p[w[i].id]^h[i-1].id) && (p[w[i-1].id]^h[i].id))
                ckmax(dp[i], dp[i-2]+1ll*w[i].val*h[i-1].val+1ll*w[i-1].val*h[i].val);
            if(i>2 && (p[w[i].id]^h[i-2].id) && (p[w[i-1].id]^h[i].id) && (p[w[i-2].id]^h[i-1].id))
                ckmax(dp[i], dp[i-3]+1ll*w[i].val*h[i-2].val+1ll*w[i-1].val*h[i].val+1ll*w[i-2].val*h[i-1].val);
            if(i>2 && (p[w[i].id]^h[i-1].id) && (p[w[i-1].id]^h[i-2].id) && (p[w[i-2].id]^h[i].id))
                ckmax(dp[i], dp[i-3]+1ll*w[i].val*h[i-1].val+1ll*w[i-1].val*h[i-2].val+1ll*w[i-2].val*h[i].val);
        }
        printf("%lld\n", dp[n]);
    }
}