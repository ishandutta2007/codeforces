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

Int n, m, ta, tb, k, a[216000], b[216000];

int main(){
    cin >> n >> m >> ta >> tb >> k;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < m;i++)cin >> b[i];
    if(n <= k || m <= k){
        cout << -1 << endl;
        return 0;
    }
    Int res = 0;
    for(int i = 0;i <= k;i++){
        Int pos = lower_bound(b, b + m, a[i] + ta) - b;
        pos += k-i;
        if(pos >= m){
            cout << -1 << endl;
            return 0;
        }
        res = max(res, b[pos] + tb);
    }
    cout << res << endl;
    return 0;
}