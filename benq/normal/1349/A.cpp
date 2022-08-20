#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdio>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
using namespace std;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int, int> pii;

ll N;
ll arr[100100];

ll freq[1200100];

set <ll> primes;

ll po(ll a, ll b) {
	ll res = 1; for (int i = 0; i < b; ++i) res *= a;
	return res;
}

int main(){
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) scanf("%lld", &arr[i]);
    for (int i = 0; i < N; i++){
        for (int j = 2; j*j <= arr[i]; j++){
            int num = 0;
            if (arr[i]%j == 0) primes.insert(j);
            while (arr[i]%j == 0){
                num++;
                freq[po(j,num)]++;
                arr[i] /= j;
            }
        }
        if (arr[i] > 1){
            primes.insert(arr[i]);
            freq[arr[i]]++;
        }
    }
    ll ans = 1;
    for (auto i = primes.begin(); i != primes.end(); i++){
        int power = 1;
        ll num = *i;
        while (po(num, power) <= 1200000 && freq[po(num, power)] >= N-1){
            power++;
        }
        ans *= po(num, power-1);
    }
    printf("%lld", ans);
}