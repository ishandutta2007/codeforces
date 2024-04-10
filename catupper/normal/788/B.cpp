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

struct uf{
    vector<int> p;
    uf(int n):p(n, -1){}

    int r(int x){
        if(p[x] < 0)return x;
        return p[x] = r(p[x]);
    }

    void merge(int x,int y){
        x = r(x);
        y = r(y);
        if(x == y)return;
        p[x] += p[y];
        p[y] = x;        
    }
    
    int size(int x){
        x = r(x);
        return -p[x];
    }
};

Int n, m;
Int a, b;
Int loop, dif;
Int deg[1100000];
bool exist[1100000];

int main(){
    scanf("%lld%lld", &n, &m);
    uf u(n);
    for(int i = 0;i < m;i++){
        scanf("%lld%lld", &a, &b);a--,b--;
        exist[a] = exist[b] = true;
        if(a == b)loop++;
        else dif++,deg[a]++,deg[b]++;
        u.merge(a, b);
    }

    int count = 0;
    for(int i = 0;i < n;i++)count += exist[i];
    int k = 0;
    while(k < n && deg[k] == 0)k++;
    if(k == n || u.size(k) != count){
        cout << 0 << endl;
    }
    else{
        Int ans = loop * (loop-1) / 2 + loop * dif;
        for(int i = 0;i < n;i++){
            ans += deg[i] * (deg[i]-1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}