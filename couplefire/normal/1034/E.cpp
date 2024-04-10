#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1<<21;

int n; string s1, s2;
ll a[N], b[N], c[N];

void OR(ll* a, int n, int x){
    for(int i = 1; i<(1<<n); i<<=1)
        for(int j = 0; j<(1<<n); j+=(i<<1))
            for(int k = 0; k<i; ++k)
                a[i+j+k] += x*a[j+k];
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s1 >> s2;
    for(int i = 0; i<(1<<n); ++i)
        a[i] = s1[i]-'0', a[i] <<= __builtin_popcount(i)<<1;
    for(int i = 0; i<(1<<n); ++i)
        b[i] = s2[i]-'0', b[i] <<= __builtin_popcount(i)<<1;
    OR(a, n, 1); OR(b, n, 1);
    for(int i = 0; i<(1<<n); ++i)
        c[i] = a[i]*b[i];
    OR(c, n, -1);
    for(int i = 0; i<(1<<n); ++i)
        cout << (c[i]>>(__builtin_popcount(i)<<1)&3);
}