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


vector<P> seg[1 << 21];
vector<int> pos[330000];

int count(int l, int r, int k){
    return upper_bound(pos[k].begin(), pos[k].end(), r) - lower_bound(pos[k].begin(), pos[k].end(), l);
}

void merge(vector<P> &a, vector<P> &b){
    for(auto p: b){
        bool done = false;
        for(int i = 0;i < a.size();i++){
            if(p.second == a[i].second){
                a[i].first += p.first;
                done = true;
            }
        }
        if(!done)a.push_back(p);
        if(a.size() <= 5)continue;
        sort(a.rbegin(), a.rend());
        for(int i = 0;i < a.size() - 1;i++){
            a[i].first -= a.back().first;
        }
        a.pop_back();
    }
}

vector<P> get(int l, int r){
    l += 1 << 20;
    r += 1 << 20;
    vector<P> res;
    while(l < r){
        if(l % 2 == 1)merge(res, seg[l++]);
        if(r % 2 == 1)merge(res, seg[--r]);
        l/=2;
        r/=2;
    }
    return res;
}


int main(){
    Int n, m, a;
    scanf("%lld%lld", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a);
        pos[a].push_back(i);
        seg[i + (1 << 20)].push_back(P(1, a));
    }

    for(int i = (1 << 20) - 1;i > 0;i--){
        seg[i] = seg[i*2];
        merge(seg[i], seg[i*2+1]);
    }
    
    for(int i = 0;i < m;i++){
        Int l, r, k;
        scanf("%lld%lld%lld", &l, &r, &k);
        auto freq = get(l, r+1);
        Int res = INF;
        for(auto p:freq){
            if(count(l, r, p.second) * k > r - l + 1)res = min(res, p.second);
        }
        if(res == INF)res = -1;
        printf("%lld\n", res);
    }
    
    return 0;
}