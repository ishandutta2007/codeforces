#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 202, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int cnt (int n) {
    int ret = 0;
    while (n) ret += n%10, n/=10;
    return ret;
}
int main() {
    int a;
    scanf ("%d",&a);
    while (cnt(a)%4!=0) a++;
    printf ("%d\n",a);
    return 0;
}