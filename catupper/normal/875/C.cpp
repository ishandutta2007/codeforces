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

vector<int> val[110000];
int n, m, k, x;

class UnionFind{
public:
    int n;
    vector<int> u;
    UnionFind(int _n = 0){
        n = _n;
        u = vector<int>(n, -1);
    }
    int r(int x){
        if(u[x] < 0)return x;
        return u[x] = r(u[x]);
    }
    void unite(int x, int y){
        x = r(x);
        y = r(y);
        if(x == y)return;
        if(-u[x] < -u[y])swap(x,y);
        u[x] += u[y];
        u[y] = x;
    }
    int size(int x){
        return -u[r(x)];
    }
};

UnionFind uf(110000);

Int big = 105000;
Int small = 107000;
vector<int> edge[110000];

void ng(){
    puts("No");
    exit(0);
}

void go(vector<int> &a, vector<int> &b){
    int k = 0;
    while(k < a.size() && k < b.size() && a[k] == b[k])k++;
    if(k == a.size())return;
    if(k == b.size())ng();
    if(a[k] < b[k]){
        edge[b[k]].push_back(a[k]);
    }
    else{
        uf.unite(big, a[k]);
        uf.unite(small, b[k]);
    }
    if(uf.r(big) == uf.r(small))ng();
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++){
        scanf("%d", &k);
        for(int j = 0;j < k;j++){
            scanf("%d", &x);
            val[i].push_back(x);
        }
    }
    for(int i = 1;i < n;i++){
        go(val[i-1], val[i]);
    }
    vector<int> ans;
    for(int i = m;i >= 1;i--){
        if(uf.r(i) == uf.r(big)){
            ans.push_back(i);
            for(auto to:edge[i])uf.unite(to, big);
        }
    }
    if(uf.r(big) == uf.r(small))ng();
    puts("Yes");
    printf("%d\n", int(ans.size()));
    for(auto a:ans)printf("%d ", a);puts("");
    return 0;
}