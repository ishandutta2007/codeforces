#include <iostream>
#include <algorithm>
#include <vector>

#include <cstring>
#include <cassert>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;

bool is_prime[max_n];

int next_prime[max_n];
int a[max_n];
int pos[max_n];
int n;

int main()
{
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    
    memset(is_prime, 1, sizeof(is_prime));

    for (int i = 2; i * i < max_n; ++i)
        if (is_prime[i])
            for (int j = i * i; j < max_n; j += i)
                is_prime[j] = false;
    
    next_prime[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        next_prime[i] = next_prime[i - 1];
        if (is_prime[i]) {
            next_prime[i] = i;
        }
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i), --a[i], pos[a[i]] = i;

    vector<pair<int, int> > swaps;

    for (int i = 0; i < n; ++i) {
        int cpos = pos[i];
        int len = cpos - i + 1;
        
        while (len > 1) {
            int prime = next_prime[len];
            int npos = cpos - prime + 1;

            swaps.push_back(make_pair(npos, cpos));
            
            swap(a[npos], a[cpos]);
            pos[a[npos]] = npos;
            pos[a[cpos]] = cpos;
            
            cpos = npos;
            len = cpos - i + 1;
        }
    }
    
    printf("%d\n", (int) swaps.size());
    for (int i = 0; i < (int) swaps.size(); ++i)
        printf("%d %d\n", swaps[i].first + 1, swaps[i].second + 1);
    
    return 0;
}