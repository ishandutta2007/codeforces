#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

int sieve[maxn];
vector<int> prime;

void linear_sieve() {
    sieve[1] = 1;
    for(int i = 2; i < maxn; i++) {
        if(sieve[i] == 0) {
            prime.push_back(i);
        }

        for(int j = 0; i * prime[j] < maxn; j++) {
            sieve[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }   
    }
}

int Max[maxn];

int main() {
    linear_sieve();
    for (int i = 0; i < prime.size(); i++) {
        for (int j = 1; prime[i] * j < maxn; j++) {
            Max[prime[i] * j] = prime[i];
        }
    }

    int n;
    scanf("%d", &n);
    int l = n - Max[n] + 1, r = n;
    int ans = maxn;
    for (int i = l; i <= r; i++) {
        if (i - Max[i] + 1 >= 3) 
            ans = min(ans, i - Max[i] + 1);
    }
    cout << ans << endl;
    return 0;
}