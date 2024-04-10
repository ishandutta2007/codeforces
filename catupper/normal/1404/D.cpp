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
#include<numeric>
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

vector<Int> nums[550000];
vector<Int> edge[1100000];
bool used[1100000];

vector<Int> ans[2];

void go(Int x, Int output = 0){
    if(used[x])return;
    used[x] = true;    
    ans[output].push_back(x);
    for(auto to:edge[x]){
        go(to, !output);
    }
}
int main(){
    Int n, x;
    cin >> n;
    if(n % 2 == 0){
        cout << "First" << endl;
        for(Int i = 1;i <= n;i++)cout << i << " ";
        for(Int i = 1;i <= n;i++)cout << i << " ";
        cout << endl;
    }
    else{
        cout << "Second" << endl;
        for(Int i = 1;i <= 2 * n;i++){
            cin >> x;
            nums[x].push_back(i);
        }
        for(Int i = 1;i <=  n;i++){
            edge[i].push_back(i+n);
            edge[i+n].push_back(i);
        }
        for(Int i = 1;i <= n;i++){
            Int u = nums[i][0], v = nums[i][1];
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(Int i = 1;i <= 2 * n;i++){
            go(i);
        }
        if(accumulate(ans[0].begin(), ans[0].end(), 0LL) % (2 * n))swap(ans[0], ans[1]);
        for(auto elem:ans[0])cout << elem << " ";
        cout << endl;
    }
    return 0;
}