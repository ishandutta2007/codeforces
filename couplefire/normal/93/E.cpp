#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long int64;
typedef long double ldb;
 
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
 
template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}
 
const int MAXK = 105;
const int magic = 100 * 1000;
 
int a[MAXK];
int ans_small[MAXK][magic];
 
long long get_ans (long long n, int k) {
    if (k == 0) {
        return n;
    }
 
    if (n < magic) {
        return ans_small[k][n];
    }
 
    return get_ans(n, k - 1) - get_ans(n / a[k - 1], k - 1);
}
 
int main () {
    ios_base::sync_with_stdio(0);
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
 
    long long n;
    int k;
    cin >> n >> k;
 
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    sort(a, a + k);
 
    if (a[0] == 1) {
        cout << 0 << endl;
        return 0;
    }
 
    for (int i = 0; i < magic; ++i) {
        ans_small[0][i] = i;
    }
 
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < magic; ++j) {
            ans_small[i][j] = ans_small[i - 1][j] - ans_small[i - 1][j / a[i - 1]];
        }
    }
 
    cout << get_ans(n, k) << endl;
 
    return 0;
}