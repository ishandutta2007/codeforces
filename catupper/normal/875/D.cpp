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
typedef pair<Int, P> T;
typedef long double Real;
typedef complex<Real> CP;

Int seg[1 << 20];
Int ans;

Int get_or(Int l, Int r){
    Int res = 0;
    l += 1<<19, r += 1<<19;
    while(l < r){
        if(l % 2)res |= seg[l++];
        if(r % 2)res |= seg[--r];
        l/=2;
        r/=2;
    }
    return res;
}
Int a[220000];

set<T> ban;
Int before[220000];
map<Int, Int> last;
int main(){
    Int n;
    cin >> n;
    Int ans = n * (n-1) / 2;
    for(Int i = 0;i < n;i++){
        scanf("%lld", &a[i]);
        seg[(1<<19) + i] = a[i];
        if(last.count(a[i]) == 0)before[i] = 0;
        else before[i] = last[a[i]] + 1;
        last[a[i]] = i;
    }
    for(Int i = (1<<19)-1;i > 0;i--)seg[i] = seg[i*2] | seg[i*2+1];
    for(Int i = 0;i < n;i++){
        Int bottom = before[i], top = i;
        if(get_or(bottom, i+1) == a[i])top = bottom;
        while(top - bottom > 1){
            Int mid = (top + bottom) / 2;
            if(get_or(mid, i + 1) == a[i])top = mid;
            else bottom = mid;
        }
        Int l = top;
        bottom = i, top = n-1;
        if(get_or(i, n) == a[i])bottom = n-1;
        while(top - bottom > 1){
            Int mid = (top + bottom) / 2;
            if(get_or(i, mid + 1) == a[i])bottom = mid;
            else top = mid;
        }
        Int r = bottom;
        ans -= (i - l + 1) * (r - i + 1) - 1;
    }
    printf("%lld\n", ans);
    return 0;
}