#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 5e6 + 1;

bool is_prime[kMaxN];
int del[kMaxN];
int amount[kMaxN];

int p[kMaxN];

int main()
{
    for (int i = 0; i < kMaxN; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < kMaxN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < kMaxN; j += i) {
                is_prime[j] = false;
                del[j] = i;
            }
        }
    }
    
    amount[0] = amount[1] = 0;
    for (int i = 2; i < kMaxN; ++i) {
        if (is_prime[i]) {
            amount[i] = 1;
        } else {
            amount[i] = 1 + amount[i / del[i]];
        }
    }
    
    p[0] = 0;
    p[1] = 0;
    for (int i = 2; i < kMaxN; ++i) {
        p[i] = p[i - 1] + amount[i];
    }

    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", p[a] - p[b]);
    }
    
    return 0;
}