/**
 *  created: 25/12/2020, 13:51:14
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 500555, inf = 1000111222;

int q, num, x[max_n];
set<pair<int, int>> a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &q);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            ++num;
            scanf("%d", &x[num]);
            x[num] *= -1;
            a.insert({num, x[num]});
            b.insert({x[num], num});
        } else if (tp == 2) {
            int num = a.begin()->first;
            printf("%d ", num);
            a.erase({num, x[num]});
            b.erase({x[num], num});
        } else {
            int num = b.begin()->second;
            printf("%d ", num);
            a.erase({num, x[num]});
            b.erase({x[num], num});
        }
    }
    puts("");
    return 0;
}