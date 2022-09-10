#include<bits/stdc++.h>
using namespace std;
const int SIZE = 300000;
const int MOD = 998244353;
int a[SIZE], b[SIZE];
int inv[SIZE];
void build_inverse(){
    inv[1] = 1;
    for ( int i=2; i<SIZE; i++ ) inv[i] = inv[MOD%i]*(MOD-MOD/i)%MOD;
}
int main()
{
    build_inverse();
    vector< pair<int,int> > AA;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        AA.emplace_back(a[i], b[i]);
    }
    sort(AA.begin(), AA.end());
    sort(a, a + n);
    sort(b, b + n);
    int now = 0;
    long long v = 1;
    long long an = 1;
    for(int i = 1; i <= n; i++) an = an * i %MOD;
    for(int i = 0; i < n; i++) {
        if(!i || a[i] != a[i-1]) now = 0;
        now++;
        v = v * now % MOD;
    }
    an -= v;
    v = 1;
    for(int i = 0; i < n; i++) {
        if(!i || b[i] != b[i-1]) now = 0;
        now++;
        v = v * now % MOD;
    }
    an -= v;
    an %= MOD;
    if(an < 0) an += MOD; 
    for(int i = 0 ; i < n; i++) {
        if(i && AA[i].second < AA[i-1].second) {
            printf("%lld\n", an % MOD);
            return 0;
        }
    }
    v = 1;
    for(int i = 0; i < n; i++) {
        if(!i || AA[i] != AA[i-1]) now = 0;
        now++;
        v = v * now % MOD;
    }
    an += v;
    an %= MOD;
    if(an < 0) an += MOD;
    printf("%lld\n", an);
}