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

bool in[3300000];
int n, x;

int main(){
    scanf("%d", &n);
    vector<int> ans = {1};
    int last = n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &x);
        in[x] = true;
        while(last > 0 && in[last])last--;
        ans.push_back(i-(n-last)+1);
    }
    for(auto v:ans)printf("%d ", v);
    puts("");
    return 0;
}