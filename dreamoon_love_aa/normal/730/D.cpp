#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <assert.h>
#include <set>

using namespace std;

long long n, r;
long long L[210000];
long long T[210000];
vector<long long> dt;
long long ans;

int main() {
    scanf("%lld%lld", &n, &r);
    for (long long i = 0; i < n; i++) scanf("%I64d", L + i);
    for (long long i = 0; i < n; i++) scanf("%I64d", T + i);
    long long cur = 0;
    long long npd = 0;
    long long rdt = 0;
    for (int i = 0; i < n; i++) {
        if (rdt >= L[i]) {
            if (T[i] < L[i]) {
                puts("-1");
                return 0;
            } else {
                rdt -= L[i];
                cur += L[i];
            }
        } else {
            long long myL = L[i] - rdt;
            long long myT = T[i] - rdt;
            cur += rdt;
            rdt = 0;
            if (myT >= myL * 2) {
                cur += myL * 2;
            } else if(myT < myL) {
                puts("-1");
                return 0;
            } else {
                long long ndt = myL * 2 - myT;
                //printf("==>%lld\n", ndt);
                long long nd = ndt / r + ((ndt % r == 0) ? 0 : 1);
                long long fdt = cur + myT - ndt;
                if (fdt < npd) {
                    puts("-1");
                    return 0;
                }
                ans += nd;
                cur += myT;
                npd = fdt + r * nd;
                rdt = r * nd - ndt;
                if (ans <= 100000) {
                    for (long long j = 0; j < nd; j++) dt.push_back(fdt + j * r);
                }
            }
        }
    }
    
    printf("%I64d\n", ans);
    if (ans <= 100000) {
        for (long long i = 0; i < ans; i++) {
            if (i != 0) putchar(' ');
            printf("%I64d", dt[i]);
        }
        putchar('\n');
    }
    
	return 0;
}