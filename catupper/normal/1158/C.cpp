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
Int a[540000];
Int b[540000];
Int dep[540000];
vector<Int> vec[540000];
Int ans[540000];
Int n, t;

void solve(){
    scanf("%lld", &n);
    
    a[n] = n;
    dep[n] = 0;
    for(int i = 0;i < n;i++){
        scanf("%lld", &a[i]);if(a[i] != -1)a[i]--;
    }
    for(int i = n-1;i >= 0;i--){
        if(a[i] == -1)a[i] = i+1;
        dep[i] = dep[a[i]] + 1;

    }
    for(int i = 0;i <= n;i++){
        vec[dep[i]].push_back(i);
    }
    int p = n+1;
    for(int i = 0;!vec[i].empty();i++){
        for(auto d:vec[i]){
            ans[d] = p--;
        }
        vec[i].clear();
    }
    b[n] = n;
    bool ng = false;
    for(int i = n-1;i >= 0;i--){
        b[i] = i+1;
        while(b[i] < n && ans[i] > ans[b[i]])b[i] = b[b[i]];
        if(b[i] != a[i])ng = true;
    }
    
    if(ng){
        printf("-1\n");
        return;
    }
    for(int i = 0;i < n;i++)printf("%lld ", ans[i]);
    printf("\n");                  
}

int main(){
    scanf("%lld", &t);
    while(t--)solve();
    return 0;
}