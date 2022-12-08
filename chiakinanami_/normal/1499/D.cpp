#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll c, d, x;
int cnt[20000002];
int num[20000002];
ll ans;
vector<ll> primes;

inline void calc(ll nc){
    ll v = x/nc + d;
    if(v % c) return;
    v /= c;

    ans += (1LL << cnt[v]);
}

const int MAX = 20000000;
void sieve(){
    for(int i=2; i<=MAX; i++) num[i] = i;
    for(int i=2; i*i<=MAX; i++){
        if(cnt[i]) continue;
        primes.push_back(i);
        for(int j=i*i; j<=MAX; j+=i){
            if(j % i) continue;
            cnt[j]++;
            while(num[j] % i == 0) num[j] /= i;
        }
    }
    for(int i=2; i<=MAX; i++){
        if(num[i] != 1) cnt[i]++;
    }
}

int main(){
    sieve();
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld", &c, &d, &x);
        ans = 0;
        for(ll i=1; i*i<=x; i++){
            if(x%i) continue;
            calc(i);
            if(i*i!=x) calc(x/i);
        }
        printf("%lld\n", ans);
    }
}