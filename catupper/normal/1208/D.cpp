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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n, ans[216000], a[216000], bit[216000];
bool used[216000];

void add(Int pos, Int val){
    pos++;
    while(pos < 216000){
        bit[pos] += val;
        pos += pos & -pos;
    }
}

Int sum(Int pos){
    pos++;
    Int res = 0;
    while(pos){
        res += bit[pos];
        pos -= pos & -pos;
    }
    return res;    
}

Int solve(Int x){
    Int bottom = 0, top = n;
    while(top - bottom > 1){           
        Int mid = (top + bottom) / 2;
        Int s = mid * (mid - 1) / 2 - sum(mid-1);
        if(s > x)top = mid;
        else if(s < x)bottom = mid;
        else if(used[mid])bottom = mid;
        else top = mid;
    }
    return top;
}


int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = n-1;i >= 0;i--){
        ans[i] = solve(a[i]);
        used[ans[i]] = true;
        add(ans[i], ans[i]);
    }
    for(int i = 0;i < n;i++)printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}