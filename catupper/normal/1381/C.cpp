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

int a[110000];
int b[110000];
int cnt[110000];
vector<int> pos[110000];
int n, x, y;

bool check(int n, int x, int y){
    fill(cnt, cnt + n + 2, 0);
    for(int i = 0;i < n;i++){
        if(a[i] == b[i])x--;
        cnt[a[i]]++;
    }
    for(int i = 0;i < n;i++){    
        if(cnt[b[i]]){
            y--;
            cnt[b[i]]--;
        }
    }
    return x==0 && y==0;
}

void solve(){
    scanf("%d%d%d", &n, &x, &y);
    for(int i = 1;i <= n+1;i++)pos[i].clear();
    priority_queue<P> pq;
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);        
        pos[a[i]].push_back(i);
    }
    int not_used;
    for(int i = 1;i <= n+1;i++){
        if(pos[i].empty())not_used = i;
        else pq.push({pos[i].size(), i});
    }
    
    int other = n - y;    
    int xx = x;
    while(xx--){
        auto tmp = pq.top();pq.pop();
        int cnt = tmp.first, num = tmp.second;
        int p = pos[num].back();pos[num].pop_back();
        b[p] = num;
        if(cnt-1)pq.push({cnt-1, num});
    }
    int largest = pq.top().first;
    vector<int> rests;
    while(!pq.empty()){
        auto tmp = pq.top();pq.pop();        
        int cnt = tmp.first, num = tmp.second;
        for(auto p:pos[num])rests.push_back(p);
    }
    for(int i = 0;i < rests.size();i++){
        b[rests[(i + largest) % rests.size()]] = a[rests[i]];
    }
    for(int i = 0;i < other;i++)b[rests[i]] = not_used;
    if(check(n, x, y)){
        puts("YES");
        for(int i = 0;i < n;i++)printf("%d ", b[i]);        
        puts("");
    }
    else{puts("NO");

    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
    return 0;
}