#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;


set<P> maxs;
vector<Int> place[110000];
int a[6];
int n, b;

int main()
{
    for(int i = 0;i < 6;i++)scanf("%d", a + i);
    scanf("%d", &n);
    vector<int> nums;
    for(int i = 0;i < n;i++){
        scanf("%d", &b);
        for(int j = 0;j < 6;j++){
            place[i].push_back(b-a[j]);
        }
        sort(place[i].begin(), place[i].end());
        maxs.insert(P(place[i].back(), i));        
    }
    Int ans = maxs.rbegin()->first - maxs.begin()->first;
    while(true){
        auto [val, pos] = *maxs.rbegin();
        maxs.erase(prev(maxs.end()));
        place[pos].pop_back();
        if(place[pos].empty())break;
        maxs.insert(P(place[pos].back(), pos));
        ans = min(ans, maxs.rbegin()->first - maxs.begin()->first);
    }
    cout << ans << endl;
    return 0;
}