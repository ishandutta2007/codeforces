#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
int ret;
int first[MN], lst[MN];
void att (int i, int j) {
    ret += first[i] > lst[j] || first[i] == -1 || lst[j] == -1;
}
int main() {
    int n,k;
    scanf ("%d %d",&n,&k);
    vector<int> a(k); memset(first,-1,sizeof first); memset(lst,-1,sizeof lst);
    for (int i = 0; i < k; i++) {
        scanf ("%d",&a[i]);
        lst[a[i]] = i;
        if (first[a[i]] == -1) first[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) { //start @ i
        if (first[i] == -1) ++ret;
        if (i>1) att(i,i-1);
        if (i<n) att(i,i+1);
    }
    printf ("%d\n",ret);
    return 0;
}