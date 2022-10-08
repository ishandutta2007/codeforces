#include <stdio.h>
#include <vector>
using namespace std;
vector <long long> ans;
long long pow(long long a, long long x) {
    long long ans = 1, i;
    for(i = 1; i <= x; i++) ans *= a;
    return ans;
}
long long get_s(long long a) {
    long long ans = 0;
    while(a > 0) {
        ans += a%10;
        a /= 10;
    }
    return ans;
}
int main() {
    long long i, a, b, c, t;
    scanf("%lld %lld %lld", &a, &b, &c);
    for(i = 1; i <= 81; i++) {
        t = b*pow(i, a)+c;
        if(t <= 0) continue;
        if(t >= 1000000000) continue;
        if(get_s(t) == i) ans.push_back(t);
    }
    printf("%d\n", ans.size());
    for(i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
    return 0;
}