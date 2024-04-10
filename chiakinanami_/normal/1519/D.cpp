#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[5002], b[5002];

ll multSum[5002];
ll ans;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=n; i++) scanf("%lld", &b[i]);

    for(int i=1; i<=n; i++){
        multSum[i] = a[i] * b[i] + multSum[i-1];
    }

    for(int d=2; d<=10000; d++){
        int si=max(1, d-n);
        ll sum = 0;
        for(int i=si; i<=d-si; i++) sum += a[d-i] * b[i];

        for(int i=si, j=d-si; i<=j; i++, j--){
            ans = max(ans, multSum[i-1] + (multSum[n] - multSum[j]) + sum);
            sum -= a[d-i] * b[i];
            sum -= a[d-j] * b[j];
        }
    }
    printf("%lld", ans);
}