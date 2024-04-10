#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

long long n, k;
string s;
vector<long long> a[33];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    for (long long i = 0; i < s.length(); ++i) {
        a[s[i] - 'a'].push_back(i);
    }
    for (long long i = 0; i < n; ++i) {
        string q;
        cin >> q;
        long long f = 0;
        for (long long j = 0; j < q.length(); ++j) {
            if (a[q[j] - 'a'].size() == 0) {
                f += q.length();
            } else {
                vector<long long>::iterator it = lower_bound(a[q[j] - 'a'].begin(), a[q[j] - 'a'].end(), j);
                long long poz1 = *it;
                --it;
                long long poz2 = *it;
                f += min(abs(j - poz1), abs(j - poz2));
            }
        }
        cout << f << endl;
    }
    return 0;
}