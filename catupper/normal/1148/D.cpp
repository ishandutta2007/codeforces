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

vector<P> up;
vector<P> down;
int n, a, b;

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a >> b;
        if(a < b)up.emplace_back(a,i+1);
        else down.emplace_back(a,i+1);
    }
    if(up.size() > down.size()){
        sort(up.rbegin(), up.rend());
        printf("%d\n", (int)up.size());
        for(auto &[a,b]:up){
            printf("%lld ",b);
        }
        printf("\n");
    }
    else{
        sort(down.begin(), down.end());
        printf("%d\n", (int)down.size());
        for(auto &[a,b]:down){
            printf("%lld ",b);
        }
        printf("\n");
    }
    
    return 0;
}