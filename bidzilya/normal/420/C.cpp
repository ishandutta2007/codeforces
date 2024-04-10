#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;

const int max_n = 3e5 + 100;

int n, p;

map<pair<int, int>, int> m2;
set<pair<int, int> > used;
int m1[max_n];
int sm1[max_n];
int x[max_n], y[max_n];

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i], --y[i];
        if (y[i] < x[i]) swap(y[i], x[i]);
        ++m1[x[i]]; ++m1[y[i]];
        ++m2[make_pair(x[i], y[i])];
    }
    for (int i = 0; i < n; ++i) 
        ++sm1[m1[i]];
    for (int i = n - 2; i >= 0; --i)
        sm1[i] += sm1[i + 1];
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        if (m1[i] >= p) {
            ans += n;
        } else {
            int j = p - m1[i];
            ans += sm1[j];
        }
    for (int i = 0; i < n; ++i)
        if (m1[i] + m1[i] >= p) 
            --ans;
    ans /= 2;
    for (int i = 0; i < n; ++i) {
        int d = m1[x[i]] + m1[y[i]];
        if (d >= p) {
            d -= m2[make_pair(x[i], y[i])];
            if (d < p) {
                if (used.find(make_pair(x[i], y[i])) == used.end()) {
                    --ans;
                    used.insert(make_pair(x[i], y[i]));
                }
            }
        }
    }
    cout << ans << endl;
            
    
    
    return 0;
}