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

Int in[220000];
Int out[220000];
Int t[220000];
Int h[220000];

vector<Int> edge[220000];

void dfs(Int x, Int last = -1){
    Int in_cnt = 0, out_cnt = 0;
    vector<Int> in_to_out;
    Int tmp = 0;
    for(auto to:edge[x]){
        if(to == last)continue;
        dfs(to, x);
        if(h[x] > h[to]){
            in_cnt++;
            tmp += out[to];
        }
        else if(h[x] < h[to]){
            out_cnt++;
            tmp += in[to];
        }
        else{
            in_cnt++;
            tmp += out[to];
            in_to_out.push_back(in[to] - out[to]);
        }
    }
    sort(in_to_out.begin(), in_to_out.end());
    in[x] = tmp + max(in_cnt + 1, out_cnt) * t[x];
    out[x] = tmp + max(in_cnt, out_cnt + 1) * t[x];
    for(Int i = 0;i < in_to_out.size();i++){
        in_cnt--;
        out_cnt++;
        tmp += in_to_out[i];
        in[x] = min(in[x], tmp + max(in_cnt + 1, out_cnt) * t[x]);
        out[x] = min(out[x], tmp + max(in_cnt, out_cnt + 1) * t[x]);
    }
}

int main(){
    Int n;
    scanf("%lld", &n);
    for(Int i = 0;i < n;i++)scanf("%lld", t + i);
    for(Int i = 0;i < n;i++)scanf("%lld", h + i);
    for(Int i = 0;i < n - 1;i++){
        Int u, v;
        scanf("%lld%lld", &u, &v);u--,v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    Int r = 0;
    while(edge[r].size() % 2 == 0)r++;
    dfs(r);
    cout << min(in[r], out[r]) << endl;
    return 0;
}