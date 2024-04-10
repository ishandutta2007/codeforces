#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <vector>

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;

#define PB push_back
#define MP make_pair
#define foreach(e,x) for(typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

LL gcd(LL a, LL b)
{
    return ! b ? a : gcd(b, a % b);
}

LL check(LL A, LL B, LL C)
{
    LL tmp = gcd(A, B);
    LL X = A * B / tmp;
    tmp = gcd(X, C);
    X = X * C / tmp;
    return X;
}

LL N;

int main()
{
 
    cin >> N;
    if (N == 1)
    {
        printf("%d\n", 1);
    }
    else
    if (N == 2)
    {
        printf("%d\n", 2);
    }
    else
    {
        long long tmp = 1;
        if (N % 2 == 1)
            cout << N * (N - 1) * (N - 2) << endl;
        else {
            tmp = max((N - 1) * (N - 2) * (N - 3), N * (N - 1) * (N - 2) / 2);
            if (tmp < check(N, N - 1, N - 3))
                tmp = check(N, N - 1, N - 3);
            if (N > 100) {
                for(int i = 1; i <= 100; ++ i)
                    for(int j = i + 1; j <= 100; ++ j)
                        if (tmp < check(N, N - i, N - j)) {
                            tmp = check(N, N - i, N - j);
                        }
            }
            cout << tmp << endl;
        }
    }
    return 0;
}