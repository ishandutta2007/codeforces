#include <cstdio>
#include <iostream>
using namespace std;
int n, k, t;
long long sum[200010], d[200010], m[200010];
int main() {
    scanf("%d%d", &n, &k);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        sum[i] = sum[i-1] + t;
    }
    int sz = 0;
    for(int i = k; i <= n; ++i) {
        d[sz] = sum[i] - sum[i-k];
        m[sz] = (sz==0? d[0] : max(m[sz-1], d[sz]));
        sz++;
    }
    long long ans = 0, fir, sec;
    for(int i = k; i <= n; ++i) {
        long long tmp = d[i] + m[i-k];
        if(tmp > ans) {
            ans = tmp;
            fir = m[i-k];
            sec = d[i];
        }
    }
//  cout << fir << ' ' << sec << ' ' << ans << endl;
    int i = 0;
    for(i = 0; i < sz; ++i)
        if(d[i] == fir) {
            cout << i+1 << ' ';
            i+=k;
            break;
        }
    for(; i < sz; ++i)
        if(d[i] == sec) {
            cout << i+1 << endl;
            break;
        }
    return 0;
}