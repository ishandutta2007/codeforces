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



Int n;
Int pos[324000];
Int a[324000];

bool ok(Int a, Int b){
    return 2 * abs(a-b) >= n;
}

vector<P> ops;

void go(Int x, Int y){
    ops.emplace_back(x,y);
    swap(a[x], a[y]);
    pos[a[x]] = x;
    pos[a[y]] = y;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 2;i < n;i++){
        if(ok(1, i)){
            if(!ok(1, pos[i])){
                go(n, pos[i]);
                go(1, n);
            }
            else{
                go(1, pos[i]);
            }
            go(1, i);
        }
        else{
            if(!ok(n, pos[i])){
                go(1, pos[i]);
                go(1, n);
            }
            else{
                go(n, pos[i]);
            }
            go(n, i);
        }
    }
    if(pos[1] != 1)go(1, n);
    printf("%d\n", (int)ops.size());
    for(auto &[l, r]:ops){
        printf("%lld %lld\n",l ,r);
    }
    return 0;
}