#include <bits/stdc++.h>

using namespace std;

bool V[600000], W[600000];

bool median(bool a, bool b, bool c) {
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    cnt[a]++; cnt[b]++; cnt[c]++;
    return cnt[0] < cnt[1];
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &V[i]);
    }

    int total = 0;


        W[1] = V[1];
        for(int i=2; i<=n-1; i++) {
            int l = 0;
            while(i+l<=n-1 && V[i+l+1] != V[i+l] && V[i+l-1] != V[i+l])
                l++;

            W[i+l] = V[i+l];
            for(int k=i, kk=i+l-1; k<=kk; k++, kk--) {
                W[k] = W[k-1];
                W[kk] = W[kk+1];
            }

            i+=l;
            total = max(total, (l+1)/2);
        }
        W[n] = V[n];

    printf("%d\n", total);
    for(int i=1; i<=n; i++) {
        printf("%d ", W[i]);
    }

    return 0;
}