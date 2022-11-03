#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <map>
#include <set>

#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int modulo = 1e9 + 7;
const int N = 1e6 + 10;

int n, m, k;
int pw[N];

int main() {
    #ifdef ONLINE_JUDGE
       // freopen("dictionary.in", "r", stdin);
       // freopen("dictionary.out", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = (2LL * pw[i-1]) % modulo;
    
    scanf("%d%d%d\n", &n, &m, &k);

    int pos_left = -1, pos_right = -1, amount = 0;
    for (; m; --m) {
        int v1, v2;
        scanf("%d%d\n", &v1, &v2);
        --v1; --v2;
        if (v2 != v1 + 1 && v2 != v1 + k + 1) {
            printf("0\n");
            return 0;
        }
        if (v2 == v1 + k + 1) {
            if (pos_left == -1) 
                pos_left = v1;
            pos_right = v1;
            ++amount;
            if (v1 >= pos_left + k + 1) {
                printf("0\n");
                return 0;
            }
        }
    }
    
    if (pos_left != -1) {
        int answer = pw[min(n - k - 2, pos_left + k) - pos_left - amount + 1];
        for (int i = 0; i < pos_left; ++i)
            if (pos_right < i + k + 1)
                answer = (answer + pw[min(n - k - 2, i + k) - i - amount]) % modulo;
        printf("%d\n", answer);
    } else { 
        int answer = 1;
        for (int i = 0; i <= n - k - 2; ++i)
            answer = (answer + pw[min(n - k - 2, i + k) - i]) % modulo;
        printf("%d\n", answer);
    }
    
    return 0;
}