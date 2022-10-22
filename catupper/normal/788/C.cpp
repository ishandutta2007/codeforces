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
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

bool exist[11000];
vector<int> edge[2200];
int dist[2200];
Int n, k, a;
Int ans = INF;

void bfs(int s){
    queue<int> q;
    fill(dist, dist + 2200, INF);
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int x = q.front();q.pop();
        if(k + x - 1000 >= 0 && exist[k + x - 1000]){
            ans = dist[x] + 1;
            return;
        }
        for(auto to:edge[x]){
            if(dist[to]!=INF)continue;
            dist[to] = dist[x] + 1;
            q.push(to);
        }
    }
}

int main(){
    scanf("%lld%lld", &k, &n);
    for(int i = 0;i < n;i++){
        scanf("%lld", &a);
        exist[a] = true;
    }

    for(int i = 0;i <= 1000;i++){
        for(int j = 0;j <= 1000;j++){
            if(!exist[j])continue;
            int mv = j - k;
            if(mv == 0){
                cout << 1 << endl;
                return 0;
            }
            if(mv > 0)
                edge[1000 - i + mv].push_back(1000-i);
            else
                edge[1000 + i + mv].push_back(1000+i);
        }
    }

    bfs(1000);
    if(ans == INF)ans = -1;
    cout << ans << endl;
    return 0;
}