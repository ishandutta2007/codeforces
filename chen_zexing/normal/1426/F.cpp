#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#define LL long long
#define MAX 100005

using namespace std;
long long mod=1000000007;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
char s[200005];
int main() {
    int n;
    long long a0 = 0, a1 = 0, ab0 = 0, ab1 = 0, ab2 = 0, abc0 = 0, abc1 = 0, abc2 = 0, abc3 = 0, ans = 0, cnt = 0;
    cin >> n;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) if (s[i] == '?') cnt++;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'c') {
            abc0 = ab0, abc0 %= mod;
            abc1 = ab1, abc1 %= mod;
            abc2 = ab2, abc2 %= mod;
            ans += abc0 * qpow(3, cnt), ans %= mod;
            if (cnt) ans += abc1 * qpow(3, cnt - 1), ans %= mod;
            if (cnt > 1) ans += abc2 * qpow(3, cnt - 2), ans %= mod;
        }
        if (s[i] == '?') {
            abc1 = ab0, abc1 %= mod;
            abc2 = ab1, abc2 %= mod;
            abc3 = ab2, abc3 %= mod;
            if (cnt) ans += abc1 * qpow(3, cnt - 1), ans %= mod;
            if (cnt > 1) ans += abc2 * qpow(3, cnt - 2), ans %= mod;
            if (cnt > 2) ans += abc3 * qpow(3, cnt - 3), ans %= mod;
        }
        if (s[i] == 'b') {
            ab0 += a0, ab0 %= mod;
            ab1 += a1, ab1 %= mod;
        }
        if (s[i] == '?') {
            ab1 += a0, ab1 %= mod;
            ab2 += a1, ab2 %= mod;
        }
        if (s[i] == 'a') a0++, a0 %= mod;
        if (s[i] == '?') a1++, a1 %= mod;
    }
    cout << ans << endl;
    return 0;
}