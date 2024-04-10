#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
    int n,a,b,k;
    scanf ("%d %d %d %d",&n,&a,&b,&k);
    vector<int> h(n); vector<int> need;
    for (auto &au : h) {
        scanf ("%d",&au);
        int fullturns = (au-1)/(a+b);
        au -= fullturns * (a+b);
        assert(au > 0);
        au -= a;
        if (au <= 0) need.push_back(0);
        else {
            assert(au <= b);
            need.push_back((au+a-1)/a);
        }
    }
    sort(all(need)); int ans = 0;

    for (int i : need) {
        if (k - i >= 0) {
            k -= i;
            ans++;
        } else {
            break;
        }
    }
    printf ("%d\n",ans);
    return 0;
}