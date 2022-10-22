#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<Int> nodes[330000];
vector<Int> edge[330000];
Int v[330000];
Int n, k, c, x;
Int cost[1320000];
Int u[1320000];

Int seg[1 << 21];

void set(Int pos, Int val){
    pos += 1 << 20;
    seg[pos] = val;
    while(pos /= 2){
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
    }
}

Int sum(Int l, Int r, Int bottom = 0, Int top = 1 << 20, Int pos = 1){
    if(l <= bottom && top <= r)return seg[pos];
    if(r <= bottom || top <= l)return 0;
    Int mid = (bottom + top )/ 2;
    return sum(l, r, bottom, mid, pos * 2) +
        sum(l, r, mid, top, pos * 2 + 1);
}

Int r(Int x){
    if(u[x] == x)return x;
    return u[x] = r(u[x]);
}

void merge(Int x, Int y){
    if(r(x) == r(y))return;
    x = r(x);
    y = r(y);
    ::set(x%k, 0);
    ::set(y%k, 0);
    Int cx = cost[x];cost[x] = 0;
    Int cy = cost[y];cost[y] = 0;
    u[y] = x;
    cost[x] = cx + cy;
}

int main(){
    cin >> n >> k;
    for(Int i = 0;i < n;i++){
        scanf("%1lld", v+i);
    }
    for(Int i = 0;i < 2 * k;i++){
        u[i] = i;
        cost[i] = i >= k;
    }
    for(Int i = 0;i < k;i++){
        scanf("%lld", &c);
        for(Int j = 0;j < c;j++){
            scanf("%lld", &x);x--;
            nodes[x].push_back(i);
        }
    }
    for(Int i = 0;i < n;i++){
        if(nodes[i].size() == 0){
            printf("%lld\n", sum(0,1<<20));
            continue;
        }
        Int a = nodes[i][0];
        Int oa = k + a;
        if(nodes[i].size() == 1){
            if(v[i] == 0)cost[r(a)] = INF;
            else cost[r(oa)] = INF;
        }
        else{
            Int b = nodes[i][1];
            Int ob = k + b;
            if(v[i] == 1){
                merge(a, b);
                merge(oa, ob);
            }
            if(v[i] == 0){
                merge(a, ob);
                merge(oa, b);
            }
        }
        a = r(a);
        oa = r(oa);
        ::set(a%k, min(cost[a], cost[oa]));
        printf("%lld\n", sum(0,1<<20));
    }
    return 0;
}